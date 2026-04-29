//剑室横梁
// written by tang

inherit ROOM;

void create()
{
	set("short", "横梁");
	set("long", @LONG
  你站在藏剑阁剑室横梁上，看见放着一个盒子(box)。
LONG
	);

	set("exits", ([           
		"down" : __DIR__"swordroom",
	]));
                                          
	set("objects", ([
			__DIR__"obj/box"	: 1,
			]));

	setup();    
        	replace_program(ROOM);
}

