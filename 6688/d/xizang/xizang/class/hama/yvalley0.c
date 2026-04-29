// /d/xizang/class/hama/yvalley0.c

inherit ROOM;

void create()
{
        set("short", "峡谷");
        set("long", @LONG
这里是雅鲁藏布江北岸的峡谷,南边不远就是汹涌澎湃的江水,涛声震耳,你
的身旁是丛生的杂草(grass)和灌木,偶尔有些动物从里面窜出来,吓你一跳.
LONG
        );
        set("exits", ([
        "west" : "/d/xizang/yvalley",
]));
        set("item_desc", ([
               "grass" : "这是一堆乱七八糟的杂草,似乎隐藏着一个洞口(hole).\n",
                "杂草" : "这是一堆乱七八糟的杂草,似乎隐藏着一个洞口(hole).\n",
                "hole" : "这个洞好象勉强可以钻进(enter)一个人.\n",
                "洞口" : "这个洞好象勉强可以钻进(enter)一个人.\n",
        ]) );
        set("objects", ([
                NPC_DIR"hama1" : random(5),
                NPC_DIR"hama2" : random(6),
        ]) );
	set("outdoors", "xizang");
        setup();
//        replace_program(ROOM);
}

void init()
{
        add_action("do_enter", "enter");
        add_action("do_enter", "zuan");
}

int do_enter(string arg)
{
        object obj, me;
        if(!arg || arg=="")
                return notify_fail("你要钻到什么地方去?\n");
        if( arg == "hole" || arg == "洞" || arg== "洞口" )
        {
                me = this_player();
                message_vision("$N拨开杂草,一矮身钻进洞口.\n", me);
                if (!(obj = find_object(__DIR__"hamadong")))
                        obj = load_object(__DIR__"hamadong");
                me->move(obj);
                message("vision", me->query("name")+
                        "拨开杂草,一矮身钻进来.\n", obj);
                return 1;
        }
        return notify_fail("你钻不进"+arg+"去\n");
}
