//zhanglao_room
inherit ROOM;

void create()
{
	set("short","长老居室");
	set("long",
@LONG
这里就是西岳庙长老所居住的地方，别看长老是西岳庙的主持，而且西
岳庙香火又极其旺盛，可是他住的地方却很简朴。只见四壁萧然，只是正中
墙上挂着一幅老道士的画像，画像飘逸出尘，却和老长老的面目迥异，不知
道究竟是谁。地上只摆放着一个蒲团。
LONG);
        set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"houyuan",
]));


	//set("outdoors","huashan");
	setup();
	replace_program(ROOM);
}

