// 幽明山庄
// by yeung. All rights reserved.

inherit "/std/room/doom.c";

void create()
{
	set("short", "幽明山庄");
	set("long", @LONG
	渐行渐远，你只觉自己脚下格格作响，似是踢到了什么东西，
又似踩碎了什么东西。你定神一看，原来一地都是白骨，更有些人似乎
死去不久，全身没有丝毫血色，全身腐烂了个七七八八，身边全是兵器
看来都是武林中人。
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
	  "northwest" : __DIR__"yongdao3",
	  "south" : __DIR__"yongdao1",
	]));

	set("objects", ([
			__DIR__"npc/obj/shigu" : 4,
		])
	);
	
	set("have_weapon",1);

	setup();
}                               
