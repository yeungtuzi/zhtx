// /d/xizang/class/budala/girl.c

inherit ROOM;

void create()
{
        set("short", "女弟子休息室");
        set("long", @LONG
这里是供丹玛女活佛的弟子休息的地方.
LONG
        );
        set("exits", ([
                "east" : __DIR__"westhall",
        ]));
        set("no_clean_up", 0);
        set("sleep_room", 1);
        set("no_faint",1);
        set("family","布达拉宫");
        setup();
}

void init()
{
        object me;
        me=this_player();
        if(me->query("gender")!="女性" && !wiz_level(me) && !raw_wiz_level(me) )
        {
                message_vision("$N只觉暗香扑面，眼前一阵晕眩，恍惚间一女子云袖轻舒，你就...\n",me);
                me->move("/d/mingjiao/hsqtan2.c");
        }
}

