/*
 * Test for Wayback comment logic
 * Tests the logic that should be in CB_HTML_stag
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Mock implementation of the logic from CB_HTML_stag */
static int inside_wayback_comment = 0;

void simulate_comment_processing(const char* tag_content) {
    printf("Processing comment: %s\n", tag_content);
    
    /* This is the logic from CB_HTML_stag for HTML_COMMENT */
    if (tag_content && strstr(tag_content, "BEGIN WAYBACK TOOLBAR INSERT")) {
        inside_wayback_comment = 1;
        printf("Wayback: Started ignoring content\n");
        return;
    }
    if (tag_content && strstr(tag_content, "END WAYBACK TOOLBAR INSERT")) {
        inside_wayback_comment = 0;
        printf("Wayback: Stopped ignoring content\n");
        return;
    }
    
    printf("Regular comment, ignoring\n");
}

void simulate_data_processing(const char* data) {
    printf("Processing data: %s\n", data);
    
    /* This is the logic from CB_HTML_data */
    if (inside_wayback_comment) {
        printf("Wayback: Ignoring data: %s\n", data);
        return;
    }
    
    printf("Normal processing: %s\n", data);
}

int main() {
    printf("Testing Wayback comment logic:\n\n");
    
    /* Simulate processing of HTML with Wayback comments */
    printf("=== Test 1: Normal content ===\n");
    simulate_data_processing("Normal content before wayback");
    
    printf("\n=== Test 2: Wayback start comment ===\n");
    simulate_comment_processing("<!-- BEGIN WAYBACK TOOLBAR INSERT -->");
    
    printf("\n=== Test 3: Content inside Wayback ===\n");
    simulate_data_processing("This content should be hidden");
    simulate_data_processing("More hidden content");
    
    printf("\n=== Test 4: Wayback end comment ===\n");
    simulate_comment_processing("<!-- END WAYBACK TOOLBAR INSERT -->");
    
    printf("\n=== Test 5: Normal content after wayback ===\n");
    simulate_data_processing("Normal content after wayback");
    
    printf("\n=== Test 6: Regular comment ===\n");
    simulate_comment_processing("<!-- This is a regular comment -->");
    simulate_data_processing("Content after regular comment");
    
    return 0;
}
