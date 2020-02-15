SRC_DIR=./single-thread_vs_multi-thread
BIN_DIR=./bin
COMPILER=g++

log () {
    echo "`date +"%T.%N" ` ${1}"
}

clean_create_bin () {
    log "cleaning bin"
    rm -rf "${BIN_DIR}*"
    rmdir "${BIN_DIR}"
    mkdir "${BIN_DIR}"
    log "done cleaning bin"
}

compile () {
    log "compiling source"
    "${COMPILER}" "${SRC_DIR}/single-thread.cpp" "${SRC_DIR}/rand-string.cpp" -I "${SRC_DIR}" -o "${BIN_DIR}/single_thread_program"
    "${COMPILER}" "${SRC_DIR}/multi-thread.cpp" "${SRC_DIR}/rand-string.cpp" -I "${SRC_DIR}" -o "${BIN_DIR}/multi_thread_program" -pthread
    log "done compiling"
}

clean_create_bin
compile
