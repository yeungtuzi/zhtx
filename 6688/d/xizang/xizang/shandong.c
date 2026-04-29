// /d/xizang/shandong.c

inherit ROOM;

void create()
{
        set("short", "雪梅洞");
        set("long", @LONG
这是一个很大的石洞(cave),洞中放着一些石桌(table),石凳(chair)和
一张石床(bed).
LONG
        );
        set("item_desc",([
        "cave" : "一个大洞\n",
        "table" : "一张桌子,上面有些刻划的痕迹\n",
        "chair" : "几个石凳子\n",
        "bed" : "一张床\n"
]));
        set("exits", ([
        "out" : __DIR__"road4",
]));

        set("objects", ([
          __DIR__"npc/feixia" : 1 ,
      ]) );

        setup();
//        replace_program(ROOM);
}
//这里增加小梅的有关物品
//
void init()
{
        remove_action("do_push","push");
        add_action("do_push", "push");
}

int do_push(string arg)
{
        if (!arg || (arg=="")) return notify_fail("你要推什么东西?\n");
        if ((arg!="凳子") && (arg!="椅子") && (arg!="chair"))
                return notify_fail("你来回推着"+arg+",累得满头大汗\n");
        remove_action("do_answer", "answer");
        add_action("do_answer", "answer");
        message_vision("你听到一个模糊的金属声音问:二加二等于几?\n"+
                       "请回答(answer)数字.\n",
                this_player());
        return 1;
}

int do_answer(string arg)
{
        string* answers = ({ "一", "二", "三", "五", "六", "七", "八",
                "九" });
        string* ansnum = ({ "1","2","3","5","6","7","8","9" });
        int correct;

        if (!arg || (arg=="")) return notify_fail("请回答数字!\n");
        correct=random(sizeof(answers));
        remove_action("do_answer", "answer");
        if ((arg==answers[correct]) || (arg==ansnum[correct])) {
                message_vision("你听到那个声音说: 答对了!\n",this_player());
                this_player()->move(__DIR__"in_cave");
                return 1;
                }
        message_vision("你听到那个声音说: 答错了!\n", this_player());
        return 1;
}
