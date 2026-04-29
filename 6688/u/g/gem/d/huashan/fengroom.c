// fengroom.c

inherit ROOM;
void create()
{
        set("short", "封不平的卧室");
        set("long", @LONG
这里就是华山剑宗掌门人封不平的卧室所在。平时
封不平就在这里，现在他就做坐在一张檀木大桌的旁边
，微笑地看着你。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"zhongting",
]));

        set("objects", ([
                CLASS_D("huashan") + "/fengbuping" : 1]));

	set("valid_startroom", 1);
        setup();
        replace_program(ROOM);
}

