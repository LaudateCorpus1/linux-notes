/*
 * Intel ACPI Component Architecture
 * AML/ASL+ Disassembler version 20200925 (32-bit version)
 * Copyright (c) 2000 - 2020 Intel Corporation
 * 
 * Disassembly of bgrt.dat, Wed Dec  9 19:30:54 2020
 *
 * ACPI Data Table [BGRT]
 *
 * Format: [HexOffset DecimalOffset ByteLength]  FieldName : FieldValue
 */

[000h 0000   4]                    Signature : "BGRT"    [Boot Graphics Resource Table]
[004h 0004   4]                 Table Length : 00000038
[008h 0008   1]                     Revision : 01
[009h 0009   1]                     Checksum : 7D
[00Ah 0010   6]                       Oem ID : "LENOVO"
[010h 0016   8]                 Oem Table ID : "CB-01   "
[018h 0024   4]                 Oem Revision : 00000001
[01Ch 0028   4]              Asl Compiler ID : "QCOM"
[020h 0032   4]        Asl Compiler Revision : 00000001

[024h 0036   2]                      Version : 0001
[026h 0038   1]       Status (decoded below) : 00
                                   Displayed : 0
                          Orientation Offset : 0
[027h 0039   1]                   Image Type : 00
[028h 0040   8]                Image Address : 00000000DC203018
[030h 0048   4]                Image OffsetX : 00000240
[034h 0052   4]                Image OffsetY : 0000011B

Raw Table Data: Length 56 (0x38)

    0000: 42 47 52 54 38 00 00 00 01 7D 4C 45 4E 4F 56 4F  // BGRT8....}LENOVO
    0010: 43 42 2D 30 31 20 20 20 01 00 00 00 51 43 4F 4D  // CB-01   ....QCOM
    0020: 01 00 00 00 01 00 00 00 18 30 20 DC 00 00 00 00  // .........0 .....
    0030: 40 02 00 00 1B 01 00 00                          // @.......
