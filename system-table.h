// Copyright 2016 The Fuchsia Authors
//
// Use of this source code is governed by a MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT

#ifndef ZIRCON_KERNEL_LIB_EFI_INCLUDE_EFI_SYSTEM_TABLE_H_
#define ZIRCON_KERNEL_LIB_EFI_INCLUDE_EFI_SYSTEM_TABLE_H_

#include <stdint.h>

#include <efi/boot-services.h>
#include <efi/protocol/simple-text-input.h>
#include <efi/protocol/simple-text-output.h>
#include <efi/runtime-services.h>
#include <efi/types.h>

#ifdef __cplusplus
extern "C" {
#endif

#define EFI_SYSTEM_TABLE_SIGNATURE 0x5453595320494249
#define EFI_2_60_SYSTEM_TABLE_REVISION ((2 << 16) | (60))
#define EFI_2_50_SYSTEM_TABLE_REVISION ((2 << 16) | (50))
#define EFI_2_40_SYSTEM_TABLE_REVISION ((2 << 16) | (40))
#define EFI_2_31_SYSTEM_TABLE_REVISION ((2 << 16) | (31))
#define EFI_2_30_SYSTEM_TABLE_REVISION ((2 << 16) | (30))
#define EFI_2_20_SYSTEM_TABLE_REVISION ((2 << 16) | (20))
#define EFI_2_10_SYSTEM_TABLE_REVISION ((2 << 16) | (10))
#define EFI_2_00_SYSTEM_TABLE_REVISION ((2 << 16) | (00))
#define EFI_1_10_SYSTEM_TABLE_REVISION ((1 << 16) | (10))
#define EFI_1_02_SYSTEM_TABLE_REVISION ((1 << 16) | (02))
#define EFI_SPECIFICATION_VERSION EFI_SYSTEM_TABLE_REVISION
#define EFI_SYSTEM_TABLE_REVISION EFI_2_60_SYSTEM_TABLE_REVISION

typedef struct {
  efi_guid VendorGuid;
  const void* VendorTable;
} efi_configuration_table;

typedef struct efi_system_table {
  efi_table_header Hdr;
  char16_t* FirmwareVendor;
  uint32_t FirmwareRevision;
  efi_handle ConsoleInHandle;
  efi_simple_text_input_protocol* ConIn;
  efi_handle ConsoleOutHandle;
  efi_simple_text_output_protocol* ConOut;
  efi_handle StandardErrorHandle;
  efi_simple_text_output_protocol* StdErr;
  efi_runtime_services* RuntimeServices;
  efi_boot_services* BootServices;
  size_t NumberOfTableEntries;
  const efi_configuration_table* ConfigurationTable;
} efi_system_table;

#ifdef __cplusplus
}
#endif

#endif  // ZIRCON_KERNEL_LIB_EFI_INCLUDE_EFI_SYSTEM_TABLE_H_
