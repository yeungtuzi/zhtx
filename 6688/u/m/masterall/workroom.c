inherit ROOM;

void create ()
{
        set ("short", "纵横工作站");
        set ("long", 
@LONG
这里就是纵横天下大管家——道全的工作站。
LONG);
        set("exits", 
        ([
                "west" : "/d/wizard/wizard_room",
                "j" : "/d/jingcheng/tamgch",
                "x" : "/d/xixia/southsquare",
                "fl" : "/d/xanadu/inn",
                "p" : "/d/xanadu/lou9",
                        ]));

        set("valid_startroom", 1);
//        set("no_fight", 1);
        setup();
}
int valid_leave(object me)
{
        if(me->query("id") != "masterall")
                        return notify_fail("这是纵横天下II大管家道全的专用通道，岂是你能随便乱走的吗？！");

        return ::valid_leave(me);
}

