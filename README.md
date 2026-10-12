# ShortWave API
Node.js REST API, upload MP4/WebM, users, follows, comments, likes, inbox, admin. Requires Node >=22.

## Termux
`bash setup-termux.sh` then `bash start-public.sh` (or `npm start` for local).

## Important
Local JSON database is a development-only store, not safe for concurrent production writes. In-memory bearer tokens expire on restart. Do not expose this MVP as a high-traffic production service without moving to PostgreSQL, durable sessions, stronger login throttling, CSRF/session architecture, malware scanning, and object storage. Set FRONTEND_ORIGIN to the exact GitHub Pages origin.

## API routes
GET /api/health, GET /api/feed, GET /api/search?q=, POST /api/register, POST /api/login, GET/PATCH /api/me, POST /api/videos, POST /api/videos/:id/like, GET/POST /api/videos/:id/comments, GET /api/users/:username, POST /api/users/:username/follow, GET/POST /api/messages/:username, GET /api/inbox, GET /api/admin/stats, DELETE /api/admin/videos/:id.
