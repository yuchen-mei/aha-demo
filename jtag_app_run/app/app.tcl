# ==============================================================================
# Declaration of Application Collateral
# ------------------------------------------------------------------------------

# ==============================================================================
# DO NOT MODIFY
# ==============================================================================
proc get_app_dir {} {
    set script_path [file normalize [info script]]
    return [file dirname $script_path]
}

proc scoped_file_name { file_name } {
    set d   [get_app_dir]
    return "$d/$file_name"
}
set APP_DIR         [get_app_dir]

# ==============================================================================
# MODIFY: App Settings
# ------------------------------------------------------------------------------

# Path to M3 Code ELF Image File
#
# NOTE: This must be an ELF file !!!
set APP_M3_CODE     [scoped_file_name test_app.elf]

# List of Memory Data To Load
#
# Each entry in the list is a 2-element list where:
#   - first element is the path to the binary data
#   - second element is the address where to load the binary data
set APP_INPUT_DATA  [list \
        [list [scoped_file_name image_2.bin] 0x20480000] \
        [list [scoped_file_name image_3.bin] 0x204C0000] \
        [list [scoped_file_name image_4.bin] 0x20500000] \
        [list [scoped_file_name image_5.bin] 0x20540000] \
        [list [scoped_file_name image_6.bin] 0x20580000] \
        [list [scoped_file_name image_7.bin] 0x205C0000] \
        [list [scoped_file_name image_8.bin] 0x20600000] \
        [list [scoped_file_name image_9.bin] 0x20640000] \
        [list [scoped_file_name image_10.bin] 0x20680000] \
    ]

# Output File Path
# - Element 1: file path
# - Element 2: Source Address
# - Element 3: Size of Data
set APP_OUTPUT_DATA [list \
        [list [scoped_file_name out_image2.bin] 0x204A0000 2904] \
        [list [scoped_file_name out_image3.bin] 0x204E0000 2904] \
        [list [scoped_file_name out_image4.bin] 0x20520000 2904] \
        [list [scoped_file_name out_image5.bin] 0x20560000 2904] \
        [list [scoped_file_name out_image6.bin] 0x205A0000 2904] \
        [list [scoped_file_name out_image7.bin] 0x205E0000 2904] \
        [list [scoped_file_name out_image8.bin] 0x20620000 2904] \
        [list [scoped_file_name out_image9.bin] 0x20660000 2904] \
        [list [scoped_file_name out_image10.bin] 0x206A0000 2904] \
]