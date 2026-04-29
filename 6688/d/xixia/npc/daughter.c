inherit NPC;

void create()
{
        set_name("卖艺女", ({ "girl" }) );
        set("gender", "女性" );
        set("age", 17);
        set("str", 16);
        set("cor", 24);
        set("cps", 11);
        set("per", 27);
        set("int", 27);

        set("attitude", "friendly");

        set("max_force", 45);
        set("force", 45);

        set("long",     "卖艺女，爷女两相依为命。\n");

        set("combat_exp", 12000);
        set("score", 274);

       set("chat_chance_combat", 5);
        set("chat_msg_combat", ({
		"卖艺女道:喂！我哪里得罪你了？干嘛这样跟我拼死拼活？\n",
         }) );

        set_skill("unarmed", 30);
        set_skill("parry", 30);
        set_skill("dodge", 60);
        set_skill("force", 30);
        set_skill("literate", 40);
        set_skill("stormdance",40);
        set_skill("fonxanforce", 30);
        set_skill("liuh-ken", 40);

        map_skill("unarmed", "liuh-ken");
        map_skill("dodge","stormdance");

        setup();
        carry_object("/obj/cloth")->wear();

}

int accept_fight(object me)
{

                if( (string)me->query("gender")=="女性" ) {
                        command("say 好姐姐，别和小妹开玩笑嘛？");
                        return 0;
                } else {
                        command("say 不，爹爹说：我们是靠这个吃饭的，不能得罪江湖上的朋友！");
                        return 0;
                }
}
