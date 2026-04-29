// /d/xizang/npc/xiaobao.c

inherit NPC;

void create()
{
        set_name("小宝", ({ "xiaobao", "kid" }) );
        set("gender", "男性" );

        set("age", 13);
        set("long", "他是汉族小男孩小宝,他父亲也在采石场工作,他家在隔壁.\n");
        set("combat_exp", 400);
        set("per", 25);
        set("inquiry", ([
               "宝藏": "真的有宝藏就好了.\n",
           "昆仑之墟": "昆仑之墟是诸神居住的地方.\n",
	     "采石场": "采石场就在城外西北山上,那里需要人帮忙.\n",
        ]) );
        set("attitude", "friendly");
        setup();
        carry_object(OBJ_DIR"cloth")->wear();
}
