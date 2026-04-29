// 幽明山庄
// by yeung. All rights reserved.

inherit "/std/room/doom.c";

void create()
{
	set("short", "七曲九回廊");
	set("long", @LONG
	这里是七、八十道长廊，相互接连，连绵不绝，直是无穷无尽。
每个长廊转弯处都有一盏宛如鬼火般摇晃不定的黄灯。廊边的潭水在灯光
照射下发出墨绿的异光。
LONG
	);

	setup();
}
