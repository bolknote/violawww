#!/bin/bash

echo "=========================================="
echo "Testing Keep-Alive + Wayback Integration"
echo "=========================================="
echo ""

# Start viola in background with debug output
echo "Starting Viola with debug output..."
echo "Look for these debug lines:"
echo "  - Keep-Alive Pool Initialized"
echo "  - DNS resolve: web.archive.org"
echo "  - HTTPS: NEW SSL connection"
echo "  - HTTPS: Server supports keep-alive"
echo "  - Keep-Alive: STORED HTTPS connection"
echo "  - Keep-Alive: REUSING HTTPS connection (on subsequent requests)"
echo ""
echo "Try loading: http://www.hackzone.ru"
echo ""
echo "Press Ctrl+C to exit when done testing."
echo ""

cd "$(dirname "$0")"
./src/viola/viola 2>&1 | tee /tmp/viola_debug.log

