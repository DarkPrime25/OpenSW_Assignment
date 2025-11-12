#!/bin/bash

file_wordcnt() {
    files=$(ls *.txt)

    for file in $files
    do
        if [ ! -f "$file" ]; then
            continue 
        fi

        result=$(cat "$file" | wc -w)
        echo "$file 파일의 단어는 ${result} 개 입니다."
    done
}

file_wordcnt