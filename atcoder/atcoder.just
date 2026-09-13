configure:
    cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug

add round letter:
    #!/usr/bin/env bash
    set -euo pipefail
    round="{{ round }}"
    contest="${round:0:3}"
    number="${round: -3}"
    mkdir -p "$contest/$number"
    cp solve.cpp "$contest/$number/{{letter}}.cpp"
    just atcoder configure

remove round letter:
    #!/usr/bin/env bash
    set -euo pipefail
    round="{{ round }}"
    contest="${round:0:3}"
    number="${round: -3}"
    rm -f "$contest/$number/{{letter}}.cpp"
    if [ -z "$(ls -A "$contest/$number")" ]; then
      rm -rf "$contest/$number"
    fi
    just atcoder configure

run round letter: configure
    #!/usr/bin/env bash
    set -euo pipefail
    round="{{ round }}"
    contest="${round:0:3}"
    number="${round: -3}"
    cmake --build build --target "$contest"_"$number"_"{{letter}}"
    ./build/"$contest"_"$number"_"{{letter}}"

export round letter:
    #!/usr/bin/env bash
    set -euo pipefail
    round="{{ round }}"
    contest="${round:0:3}"
    number="${round: -3}"
    { cat main.hpp; echo ""; echo ""; awk '
    /auto[ \t]+solve[ \t]*\([^)]*\)[ \t]*->/ { found=1 }
    found {
        print
        depth += gsub(/{/, "{") - gsub(/}/, "}")
        if (depth > 0) started = 1
        if (started && depth == 0) exit
    }
    ' "$contest/$number/{{letter}}.cpp"; } | wl-copy
