// /clone/board/huashan_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("桃花岛弟子留言板", ({ "board" }) );
        set("location", "/d/taohua/dating");
        set("board_id", "taohua_b");
        set("long", "这是一个供桃花岛弟子交流的留言板。\n" );
        setup();
        set("capacity", 30);
        replace_program(BULLETIN_BOARD);
}
