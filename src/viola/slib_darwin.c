/*
 * Sound Library - macOS implementation using AudioToolbox C API
 * Replaces ObjC-based NSSound/AVFoundation implementation
 */
#ifdef __APPLE__

#include <AudioToolbox/AudioToolbox.h>
#include <CoreFoundation/CoreFoundation.h>
#include <string.h>
#include <unistd.h>

#define NUM_BUFFERS 3

static float g_bellVolume = 1.0f;  /* 0.0 to 1.0 */

typedef struct {
    AudioFileID audioFile;
    AudioQueueRef queue;
    AudioStreamBasicDescription dataFormat;
    SInt64 currentPacket;
    UInt32 bufferByteSize;
    volatile int isRunning;
} AQPlayerState;

/* Callback for Audio Queue - fills buffer with audio data */
static void HandleOutputBuffer(void *userData, AudioQueueRef queue, AudioQueueBufferRef buffer) {
    AQPlayerState *state = (AQPlayerState *)userData;
    
    if (!state->isRunning) return;
    
    UInt32 numBytes = state->bufferByteSize;
    
    /* Use AudioFileReadBytes for CBR formats like AIFF */
    SInt64 byteOffset = state->currentPacket * state->dataFormat.mBytesPerPacket;
    
    OSStatus status = AudioFileReadBytes(
        state->audioFile,
        false,
        byteOffset,
        &numBytes,
        buffer->mAudioData
    );
    
    if (status == noErr && numBytes > 0) {
        buffer->mAudioDataByteSize = numBytes;
        AudioQueueEnqueueBuffer(queue, buffer, 0, NULL);
        state->currentPacket += numBytes / state->dataFormat.mBytesPerPacket;
    } else {
        /* End of file or error */
        state->isRunning = 0;
        AudioQueueStop(queue, false);
    }
}

/* Play a sound file using Audio Queue Services */
static void play_sound_file(const char *path) {
    AQPlayerState state = {0};
    OSStatus status;
    
    /* Open audio file */
    CFURLRef audioFileURL = CFURLCreateFromFileSystemRepresentation(
        kCFAllocatorDefault,
        (const UInt8 *)path,
        strlen(path),
        false
    );
    
    if (!audioFileURL) {
        return;
    }
    
    status = AudioFileOpenURL(audioFileURL, kAudioFileReadPermission, 0, &state.audioFile);
    CFRelease(audioFileURL);
    
    if (status != noErr) {
        return;
    }
    
    /* Get audio format */
    UInt32 dataFormatSize = sizeof(state.dataFormat);
    AudioFileGetProperty(state.audioFile, kAudioFilePropertyDataFormat, &dataFormatSize, &state.dataFormat);
    
    /* Create Audio Queue */
    status = AudioQueueNewOutput(
        &state.dataFormat,
        HandleOutputBuffer,
        &state,
        CFRunLoopGetCurrent(),
        kCFRunLoopCommonModes,
        0,
        &state.queue
    );
    
    if (status != noErr) {
        AudioFileClose(state.audioFile);
        return;
    }
    
    /* Set volume */
    AudioQueueSetParameter(state.queue, kAudioQueueParam_Volume, g_bellVolume);
    
    /* Buffer size: 0.5 seconds of audio */
    state.bufferByteSize = (UInt32)(state.dataFormat.mSampleRate * 0.5 * state.dataFormat.mBytesPerPacket);
    
    /* Allocate and prime buffers */
    state.isRunning = 1;
    state.currentPacket = 0;
    
    AudioQueueBufferRef buffers[NUM_BUFFERS];
    for (int i = 0; i < NUM_BUFFERS; i++) {
        AudioQueueAllocateBuffer(state.queue, state.bufferByteSize, &buffers[i]);
        HandleOutputBuffer(&state, state.queue, buffers[i]);
    }
    
    /* Start playback */
    status = AudioQueueStart(state.queue, NULL);
    if (status != noErr) {
        AudioQueueDispose(state.queue, true);
        AudioFileClose(state.audioFile);
        return;
    }
    
    /* Run loop until playback completes */
    while (state.isRunning) {
        CFRunLoopRunInMode(kCFRunLoopDefaultMode, 0.1, false);
    }
    
    /* Wait for queue to flush */
    usleep(100000);
    
    /* Cleanup */
    AudioQueueDispose(state.queue, true);
    AudioFileClose(state.audioFile);
}

void SLBell_Darwin(void) {
    const char *path = "/System/Library/Sounds/Tink.aiff";
    play_sound_file(path);
}

int SLBellVolume_Darwin(int percent) {
    if (percent >= 0 && percent <= 100) {
        g_bellVolume = percent / 100.0f;
    }
    return (int)(g_bellVolume * 100);
}

void SLPlaySound_Darwin(const char *path) {
    if (!path) return;
    play_sound_file(path);
}

#endif /* __APPLE__ */
