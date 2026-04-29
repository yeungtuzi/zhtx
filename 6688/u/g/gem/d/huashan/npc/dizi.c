// xiaotong.c 小童
inherit __DIR__"qi_npc.c";

void create()
{
         set_name("华山弟子", ({ "huashan dizi", "dizi"}));
        set("long",
                "一个精壮的华山派弟子，他正在练功\n");
        set("gender", "男性");
        set("age", 22);
        set("attitude", "peaceful");
        set("shen_type", 1);

        set("str", 40);
        set("int", 40);
        set("con", 40);
        
        set("max_kee", 500);
        set("max_gin", 500);
        set("force", 500);
        set("max_force", 500);

        set("combat_exp", 100000);
        set("score", 1000);

        set_skill("force", 40);
        set_skill("dodge", 40);
        set_skill("unarmed", 40);
        set_skill("parry", 40);
        set_temp("apply/attack", 15);
        set_temp("apply/defense", 15);
        set_temp("apply/damage", 5);

        create_family("华山派", 21, "弟子");

        setup();

        carry_object("/obj/cloth")->wear();
}
