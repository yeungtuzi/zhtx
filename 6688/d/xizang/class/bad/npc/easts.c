// /d/xizang/class/bad/npc/easts.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("花云", ({ "easts", "hua yun", "hua", "yun" }));
	set("title", GRN+"华山大师姐"+NOR);
	set("gender", "女性" );
	set("age", 32);
	set("str", 24);
	set("cor", 29);
	set("cps", 22);
	set("int", 27);
	set("per", 25);
	set("long", @TEXT
她是华山派的大师姐花云,据说实际年龄已经很大了,不过看上去并不显老.她
练功很勤,不爱说话,剑法极高,是风清扬的得意弟子之一.
TEXT
);
	set("combat_exp", 4200000);
	set("force", 3500);
        set("max_force", 3500);
	set("force_factor", 150);
	set("attitude", "heroism");
	set_skill("unarmed", 200);
	set_skill("parry", 200);
	set_skill("dodge", 180);
	set_skill("dugu-jiujian", 280);
	set_skill("sword", 299);
        set_skill("move", 199);
        set_skill("force", 239);
        set_skill("zixia-shengong", 200);
        set_skill("huashan-jianfa", 199);

        map_skill("sword", "dugu-jiujian");
        map_skill("parry", "dugu-jiujian");
        map_skill("force", "zixia-shengong");
        map_skill("dodge", "huashan-shenfa");
        map_skill("move","huashan-shenfa");
        map_skill("unarmed", "huashan-zhangfa");	
	setup();
	carry_object("/obj/cloth")->wear();
	carry_object("/obj/weapon/gangjian")->wield();
}

//add helping
