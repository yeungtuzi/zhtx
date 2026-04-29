// /obj/board/letter_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("TASK BUG汇报留言板",({"board"}));
        set("location", "/d/jingcheng/postoffice");
        set("board_id", "letter_b");
        set("long", "请将不能完成任务的npc名字和颜色留在这里，谢谢合作。\n");
	setup();
	set("capacity", 30);
	replace_program(BULLETIN_BOARD);
}

