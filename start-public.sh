#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
node api/server.js & PID=$!
trap 'kill "$PID" 2>/dev/null || true' EXIT INT TERM
sleep 2
kill -0 "$PID" || exit 1
cloudflared tunnel --url "http://127.0.0.1:${PORT:-3000}"
