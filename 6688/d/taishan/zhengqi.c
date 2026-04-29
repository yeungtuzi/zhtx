// Room: /d/taishan/zhengqi.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
        set("short", "正气厅");
        set("long", @LONG
这里是封禅台右边的正气厅，武林盟罚恶使者平时不下山时，
通常都是在这里处置武林公案。上首正中放着把虎皮椅，罚恶使者
就坐在上面开堂审理。左右各侍立着几位红衣武士，看上去杀气腾
腾，令人凛然而生惧意。
LONG
        );

        set("exits", ([
                "east" : __DIR__"fengchan",
        ]));

        set("objects",([
//                __DIR__"npc/fa-e" : 1,
                __DIR__"npc/wei-shi2" : 3,
        ]));

        set("no_clean_up", 1);

        setup();
}

void init()
{       
        add_action("do_get","get");
        add_action("do_steal","steal");
}

int do_get(string arg)
{
                write( "这儿不准乱拿东东\n" );
                return 1;
}

int do_steal(string arg)
{
                write( "这儿严禁行窃\n" );
                return 1;
}
