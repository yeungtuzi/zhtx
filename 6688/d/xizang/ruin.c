// /d/xizang/ruin.c

#include <ansi.h>
#include <skill.h>
inherit ROOM;

void create()
{
        set("short", "昆仑之墟");
        set("long", @LONG
这里就是传说中诸神居住的圣地昆仑之墟,这里空荡荡的似乎千百年来都
没有人来过,在你的四周是一大片冰柱构成的丛林. 而你面前则是一块数丈高
的青色巨石,石上约一人高处,不知是谁用什么利器刻下了一个八卦(script),
除此之外再无任何特异之处.
LONG
        );
        set("item_desc", ([
 "script" : "这就是一个普通的八卦,不过阴阳鱼的眼睛(eyes)似乎有点儿特别.\n",
   "eyes" : "这对眼睛是分别用黑白两色宝石镶嵌成的,好象两个按钮(button)\n",
 "button" : "你观察了一会儿,觉得这两个按钮可以按(push)动.\n",
]));

        set("exits", ([
            "north" : __DIR__"ice1",
            "south" : __DIR__"ice9",
             "east" : __DIR__"ice7",
             "west" : __DIR__"ice3",
]));

        setup();
}

void init()
{
        object ob;
        if( interactive( ob = this_player()))
        {
                ob->set("marks/昆仑之墟", 1);
                remove_action("do_push", "push");
                add_action("do_push", "push");
        }
}

int do_push(string arg)
{
        string button, xx, yy;
        object who, room;
        int skill, exp;
        string *xpos= ({ "a", "b", "c", "d", "e" });
        string *ypos= ({ "1", "2", "3", "4", "5" });

        if (!interactive( who = this_player() )) return 0;
        if (!arg) return notify_fail("你要按什么?\n");
        if (sscanf(arg, "%s button", button) != 1)
                return notify_fail("你要按哪个按钮?\n");
        if ((button!="black") && (button!="white"))
                return notify_fail("只有黑(black),白(white)两个按钮可以按.\n");
        exp = who->query("combat_exp");
        skill = who->query_skill("navigation", 1);
        if (button=="black") {
                if (exp<500000) {
message_vision(HIC"半空中响起一个巨大的声音:$N没有资格!\n"NOR,who);
                return 1;
                }
                if (exp>=500000) {
message_vision(HIC"$N按动黑色按钮,半空中响起一个巨大的声音:出发了!\n"NOR, who);
                        if (skill<=10) {
message_vision(HIC"$N导航技术太差,落进了沙漠!\n"NOR, who);
			exp=who->query("int");
			who->improve_skill("navigation", 1+random(exp));
                        xx = xpos[random(sizeof(xpos))];
                        yy = ypos[random(sizeof(ypos))];
                        room=find_object("/d/sandland/desert"+xx+yy);
                        who->move(room);
                        return 1;
                        }
                remove_action("do_select", "select");
                add_action("do_select", "select");
                return 1;
                }
        } //end of black button == flying
        if (button=="white") {
                return notify_fail("这个按钮按不动!\n");
        }
}

int do_select(string arg)
{
        object who, room;
        who = this_player();
        if (!arg) return notify_fail("你到底要去哪里?\n");
        if (arg=="6868") return notify_fail("你已经在西藏了.\n");
        if (arg=="1717") {
                room = find_object("/d/snow/temple");
                message_vision(HIC"这就送$N去雪亭镇!\n"NOR, who);
                who ->move(room);
                message_vision(HIC"$N出现在一团烟雾中.\n"NOR, who, room);
                return 1;
        }
        if (arg=="zgc" || arg=="ZGC") {
                room = find_object("/d/peking/temple");
                message_vision(HIC"这就送$N去中关村!\n"NOR, who);
                who ->move(room);
                message_vision(HIC"$N出现在一团烟雾中.\n"NOR, who, room);
                return 1;
        }
        return notify_fail("去向不明!\n");
}

int valid_leave(object me, string dir)
{
        object room;
        string outexit;
                switch (random(4)) {
                case 0:
                        outexit = __DIR__"ice6";
                        break;
                case 1:
                        outexit = __DIR__"ice7";
                        break;
                case 2:
                        outexit = __DIR__"ice8";
                        break;
                case 3:
                        outexit = __DIR__"ice9";
                        break;
                }
        if (dir == "north") {
                if ( query("exits/north") ) delete("exits/north");
                set("exits/north", outexit);
        } else if (dir == "south") {
                if ( query("exits/south") ) delete("exits/south");
                set("exits/south", outexit);
        } else if (dir == "east") {
                if ( query("exits/east") ) delete("exits/east");
                set("exits/east", outexit);
        } else if (dir == "west") {
                if ( query("exits/west") ) delete("exits/west");
                set("exits/west", outexit);
        }
        return 1;
}
