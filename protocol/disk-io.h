// Copyright 2016 The Fuchsia Authors
//
// Use of this source code is governed by a MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT

#ifndef ZIRCON_KERNEL_LIB_EFI_INCLUDE_EFI_PROTOCOL_DISK_IO_H_
#define ZIRCON_KERNEL_LIB_EFI_INCLUDE_EFI_PROTOCOL_DISK_IO_H_

#include <efi/boot-services.h>
#include <efi/runtime-services.h>
#include <efi/types.h>

#ifdef __cplusplus
extern "C" {
#endif

#define EFI_DISK_IO_PROTOCOL_GUID                                                  \
  {                                                                                \
    0xCE345171, 0xBA0B, 0x11d2, { 0x8e, 0x4F, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b } \
  }

extern const efi_guid DiskIoProtocol;

#define EFI_DISK_IO_PROTOCOL_REVISION 0x00010000

typedef struct efi_disk_io_protocol efi_disk_io_protocol;

struct efi_disk_io_protocol {
  uint64_t Revision;
  efi_status (*ReadDisk)(efi_disk_io_protocol* self, uint32_t MediaId, uint64_t Offset,
                         uint64_t BufferSize, void* Buffer) EFIAPI;
  efi_status (*WriteDisk)(efi_disk_io_protocol* self, uint32_t MediaId, uint64_t Offset,
                          uint64_t BufferSize, const void* Buffer) EFIAPI;
};

#ifdef __cplusplus
}
#endif

#endif  // ZIRCON_KERNEL_LIB_EFI_INCLUDE_EFI_PROTOCOL_DISK_IO_H_
