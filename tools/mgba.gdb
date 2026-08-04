set architecture arm
set pagination off
set confirm off
set remotetimeout 5
set disassemble-next-line off

define sb-state
  printf "pc/lr/sp and argument registers:\n"
  info registers pc lr sp r0 r1 r2 r3 cpsr
  x/8i $pc
end
document sb-state
Show the current call-site registers and nearby instructions.
end

define sb-frame
  tbreak *0x080007CA
  continue
  printf "Stopped at the Sonic Battle main-loop frame boundary.\n"
  sb-state
end
document sb-frame
Advance to the next main-loop iteration (one normal game frame).
end

define sb-frames
  set $sb_frame_count = 0
  while $sb_frame_count < $arg0
    tbreak *0x080007CA
    continue
    set $sb_frame_count = $sb_frame_count + 1
  end
  printf "Advanced %u main-loop frames and stopped at 0x080007CA.\n", $sb_frame_count
  sb-state
end
document sb-frames
Advance multiple main-loop frames, for example: sb-frames 60
end

define sb-boot
  tbreak *0x08000778
  continue
  printf "Stopped at AgbMain. Use sb-frame to reach successive frame boundaries.\n"
  sb-state
end
document sb-boot
Run from reset to Sonic Battle's AgbMain entry point.
end

define sb-break
  break *$arg0
end
document sb-break
Set an execution breakpoint at an address, for example: sb-break 0x08018318
end

define sb-watch8
  watch *(unsigned char *)$arg0
end
document sb-watch8
Watch an 8-bit memory location, for example: sb-watch8 0x030016C4
end

define sb-watch16
  watch *(unsigned short *)$arg0
end
document sb-watch16
Watch a 16-bit memory location, for example: sb-watch16 0x03001B04
end

target remote 127.0.0.1:2345
printf "Connected to mGBA. Commands: sb-boot, sb-frame, sb-frames, sb-state, sb-break, sb-watch8, sb-watch16.\n"
sb-state
