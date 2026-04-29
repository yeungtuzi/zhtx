// /d/xizang/npc/yangzong.c

inherit NPC;

void create()
{
        set_name("央宗", ({ "yangzong", "kid" }) );
        set("gender", "女性" );

        set("age", 12);
        set("long", "她是藏族小女孩央宗,她的父亲是采石场的工人.\n");
        set("combat_exp", 200);
        set("per", 29);
        set("inquiry", ([
               "宝藏": "真的有宝藏就好了.\n",
           "昆仑之墟": "昆仑之墟是诸神居住的地方.\n",
	     "采石场": "采石场在城外西南山上,小宝才来不久,分不清东西南北.\n",
        ]) );
        set("attitude", "friendly");
        setup();
        carry_object(__DIR__"obj/skirt")->wear();
}
