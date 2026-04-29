// 幽明山庄
// by yeung. All rights reserved.

inherit ROOM;

void create()
{
        set("short", "枫林小栈");
        set("long", @LONG
        这是枫林渡口旁边的一个小酒家，破烂的酒旗在北风中飞舞。北面的路通往
曾经声名显赫一时的幽明山庄。自从幽明山庄的凶讯传扬开去之后，这里就变得非常冷清了。只有要去幽明山庄探明究竟的人才会在这里喝点酒，壮一壮胆，攒足精神。
LONG
        );

        set("valid_startroom",1);
        //别看限制挺严格，其实可以杀人的呀，因为已经算幽明山庄的地界了
        set("sleep_room",1);
        set("no_fight",1);  
        set("no_poison",1);
        set("no_magic",1);  
        set("no_steal",1);
        set("no_death",1);
        set("no_get",1);
        set("no_faint",1);
        set("exits", ([ /* sizeof() == 2 */
          "north" : __DIR__"dukou",
          "southeast" : "/d/road/changbaishan",
        ]));                                     

        set("objects", ([
                          "/d/chengdu/npc/waiter" : 1,
                          __DIR__"npc/qiaofeng" : 1,
                ])
        );

        setup();
}

int do_buy()
{
        write("在这里买东西？不怕别人抢了你的钱？\n");
        return 1;
}

