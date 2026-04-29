inherit ROOM;

void create ()
{
        set ("short", "纵横工作站");
        set ("long", 
@LONG
这里就是纵横天下巫师——旭心的工作站。
LONG);
        set("exits", 
        ([
                "west" : "/d/wizard/wizard_room",
                "j" : "/d/jingcheng/tamgch",
                "x" : "/d/xixia/southsquare",
                "fl" : "/d/xanadu/inn",
                "p" : "/d/xanadu/lou9",
                "k" : "/u/z/zhxx/xiangyang/tiantang",
                        ]));

        set("valid_startroom", 1);
//        set("no_fight", 1);
        setup();
}
