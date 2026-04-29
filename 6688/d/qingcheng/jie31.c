// Room: /d/qingcheng/jie31.c

inherit ROOM;

void create()
{
	set("short", "[33m福州大街[2;37;0m");
	set("long", @LONG
 这里的街道非常宽广,小贩们在使劲的吆喝,希望能多做些生意.
而行人则边走边看,要是有合适的货物,便停下来挑选,讨价还价的.不时
走来一两个地痞流氓,在大街上横冲直撞.那些老实的生意人被他们欺负
得多了,见到他们来了,不禁屏住呼吸,生怕惹事上身.
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"jie21",
		"east" : __DIR__"shuyuan",
		"south" : __DIR__"jie41",
		"west" : __DIR__"weapon",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
