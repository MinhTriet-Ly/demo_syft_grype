# syft-grype demo
Minimal cmake project with conanfile to demonstrate the usage of syft/grype to do sbom-eval

* Install tools

using latest [syft](https://github.com/anchore/syft) and [grype](https://github.com/anchore/grype) versions

```sh
curl -sSfL https://raw.githubusercontent.com/anchore/syft/main/install.sh | sudo sh -s -- -b /usr/local/bin
curl -sSfL https://raw.githubusercontent.com/anchore/grype/main/install.sh | sudo sh -s -- -b /usr/local/bin
```

* Configure and build project

```sh
mkdir build && cd build
CC=clang-16 CXX=clang++-16 cmake -DCMAKE_BUILD_TYPE=debug -GNinja .. && ninja
```

* Run check

```sh
syft scan dir:${HOME}/proj/demo_syft_grype/build --scope=AllLayers --select-catalogers=conan --source-name=demo --output cyclonedx-json=syft.json
grype -o json sbom:syft.json > grype.json
```