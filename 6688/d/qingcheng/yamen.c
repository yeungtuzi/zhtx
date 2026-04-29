// /d/qingcheng/yamen.c

inherit ROOM;

void create()
{
        set("short", "福州府衙");
        set("long", @LONG
    这里是福州城的衙门，两扇大门紧紧关闭着。大门上的牌匾上刻着几
个大字：福州府衙，门前有一个大鼓。福州府尹当中而做，十几名衙役
分居两旁，各自举着肃静、回避的牌匾。有不少人出出进进，络绎不绝。
LONG
        );

        set("exits", ([
                "west" : "/d/qingcheng/jie41",
        ]));

        set("objects", ([
                "/d/qingcheng/npc/fuyin" : 1,
        ]));

        setup();
        replace_program(ROOM);
}


