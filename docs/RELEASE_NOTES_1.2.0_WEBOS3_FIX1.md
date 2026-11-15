# UxAir 1.2.0 webOS 3 compatibility fix 1

This downstream build uses OpenSSL's `--with-rand-seed=devrandom` configuration to obtain secure randomness from available OS devices such as `/dev/urandom`. The upstream build failed to initialize its receiver on an LG 60UH8500-CA with webOS 3.4.3 and firmware 05.70.45. After manually provisioning the missing device ID during diagnosis, the log exposed the underlying failure during Ed25519 key generation: `entropy source strength too weak`.

The attached Starfish IPK was installed over the previous build on that TV. UxAir reported ready, macOS discovered its AirPlay service, and the tester confirmed that the Mac desktop appeared on the TV. The TV already had an app-local device ID from diagnosis. Fresh installation, audio, reboot persistence and other models were not verified.

The IPK retains upstream app version 1.2.0 and application ID `com.github.depius.uxair`. Its embedded build commit identifies the upstream checkout used for the real-device test. This release tag adds the exact tested build change and this note. The corresponding source archive includes the pinned dependency sources and build scripts.

Install on a compatible rooted TV with native app support enabled. Back up existing UxAir private state before installing over a prior build. Verify the IPK against `SHA256SUMS`, then install with `ares-install -d YOUR_TV PATH_TO_IPK`. Launch UxAir on the TV and select it from macOS Screen Mirroring.
