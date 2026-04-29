// hole.c 小洞

inherit ROOM;

void create()
{
        set("short", "小洞");
		set("long", 
@LONG
这里是个很黑很小的小洞，一眼看过去似乎都看不清洞底在哪里，只能隐
隐约约看见有个人影在洞的深处。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
		  "out" : __DIR__"yunv",
		  
	]));
        set("objects", ([
                 __DIR__"npc/feng":1,//风清扬
				 
]));

        setup();
        replace_program(ROOM);
}
 
