BIN_DIR=./bin

log () {
    echo "`date +"%T.%N" ` ${1}"
}

run () {
    log "starting single_thread_program"
    st_time_before=$(date +%s%N)
    "${BIN_DIR}/single_thread_program"
    st_time_after=$(date +%s%N)
    log "single_thread_program completed"


    log "starting multi_thread_program"
    mt_time_before=$(date +%s%N)
    "${BIN_DIR}/multi_thread_program"
    mt_time_after=$(date +%s%N)
    log "multi_thread_program completed"

    log "time taken by single thread program = $((st_time_after-st_time_before)) ns"
    log "time taken by multi thread program  = $((mt_time_after-mt_time_before)) ns"
}

run

