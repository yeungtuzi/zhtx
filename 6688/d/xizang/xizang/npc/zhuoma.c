// /d/xizang/npc/zhuoma.c

inherit NPC;

void create()
{
        set_name("卓玛", ({ "zhuoma", "girl" }) );
        set("gender", "女性" );

        set("age", 16);
        set("long", @LONG
她是藏族少女卓玛,因为放牧的羊被狼群抢去吃了,正在伤心中.
LONG
);
        set("combat_exp", 1000);
        set("per", 29);
        set("inquiry", ([
               "宝藏": "真的有宝藏就好了.\n",
           "昆仑之墟": "昆仑之墟是诸神居住的地方.\n",
		 "狼": "真希望有位英雄来除掉城外的恶狼.\n",
	       "英雄": "冰川之王格萨尔是我们藏族最伟大的英雄.\n",
	     "格萨尔": "他好象就住在南面的大山里,不久前还有人见过他.\n"
        ]) );
	set_skill("whip", 20);
        set_skill("parry", 5);
        set_skill("dodge", 10);
        set("attitude", "friendly");
        setup();
        carry_object(__DIR__"obj/skirt")->wear();
}
