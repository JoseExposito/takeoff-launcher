FILE(GLOB_RECURSE PO_FILES *.po)

add_translations(takeoff ${PO_FILES})
