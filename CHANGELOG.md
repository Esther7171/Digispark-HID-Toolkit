# Changelog

All notable changes to Digispark HID Toolkit are documented here.

Format follows [Keep a Changelog](https://keepachangelog.com/en/1.0.0/).
Versioning follows [Semantic Versioning](https://semver.org/).

---

## [2.0.0] - 2026-06-22

### Added
- Discord webhook integration (`digispark/discord/r00t_b0t.ino`)
- Discord PowerShell payload (`scripts/null.ps1`)
- Windows Event Log clearing via `wevtutil cl`
- Deep Telegram and Discord setup documentation
- CONTRIBUTING, SECURITY, CODE_OF_CONDUCT, CHANGELOG files
- GitHub Actions workflows for linting and releases
- `docs/` directory with integration guides
- `examples/` directory with beginner sketches

### Changed
- Repository rebranded as Digispark HID Toolkit
- Telegram sketch moved to `digispark/telegram/r00t_b0t.ino`
- README fully rewritten with SEO optimization
- File structure reorganized into telegram and discord subdirectories

### Fixed
- Telegram sketch was nested under incorrect `digispark/telegram/digispark/` path
- Discord sketch had a hardcoded webhook URL instead of a placeholder

---

## [1.0.0] - 2026-01-01

### Added
- Initial release as DigiStrike
- Telegram-based WiFi credential exfiltration
- PowerShell payload (`scripts/void.ps1`)
- Zero trace cleanup: temp file, PS history, registry MRU
- BSD 3-Clause license
