// Room: /d/choyin/w_street1.c

inherit ROOM;

void create()
{
        set("short", "西大街");
        set("long", @LONG
这里是乔阴县城的西大街，西边就是县城的西门，一座巨大的牌楼
上刻著「西门」二字，往北有一条小巷，南边则是一间书肆，街道中央
立著一尊石狮(statue)，而且是站著的，将来往行人分为左右两道。
LONG
        );
        set("item_desc", ([ /* sizeof() == 1 */
  "statue" : "这尊石狮跟一般寻常人家放在门口镇宅避邪的石狮颇有不同，姿势
是立著的，而且大小要大得多，只怕有几万斤重，你注意到石狮的额头
上 刻著一个「□」字，不知是何用意？
",
]));
        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"w_street2",
  "west" : __DIR__"w_gate",
]));
        set("no_clean_up", 0);
        set("outdoors", "choyin");

        setup();
        replace_program(ROOM);
}
