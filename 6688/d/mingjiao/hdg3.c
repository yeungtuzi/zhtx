
inherit ROOM;

void create()
{
        set("short", "门外");
        set("long", @LONG
	这是蝴蝶谷里面的一块空地，北面是一座小小的庄院。据说“医仙”
胡青牛就隐居此地。他性情怪僻，以见死不救而闻名。因此，不到万不得已，
也真没有几个人来求他医治。门外躺着几个江湖豪客，显然也是求医未果。
LONG
        );
        set("exits", ([ 
  "enter" : __DIR__"hdj",
  "south" : __DIR__"hdg2",
]));
        set("outdoors", "mingjiao");
//        set("objects", ([
//                __DIR__"npc/jintong" : 1,
//        ]) );

        setup();
        replace_program(ROOM);
}

