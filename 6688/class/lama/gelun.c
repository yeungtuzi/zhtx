
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("葛伦", ({ "master gelun", "master","gelun" }) );
	set("gender", "男性" );
	set("age", 99);
	set("int", 30);
	set("no_get",1);
	set("shen_type",-1);
        set("apprentice_available", 1);
        create_family("大招寺", 20, "主持");
	set("long",
		"葛伦高僧已在大招寺主持多年。男女弟子遍布西藏。\n现在他已经把住持教给了灵空，自己一心研习佛法。\n"
		);
	set("inquiry", ([
		"舍利子": "嗯....舍利子.....在舍利塔里。\n",
		"普松": "普松在大招寺的木屋里。",
	]) );
        set("combat_exp", 29999999);
        set("score", 90000);

	set("atman",3000);
	set("max_atman",3000);
	set("kee",1000);
	set("max_kee",1000);
	set("sen",1000);
	set("max_sen",1000);
	set("force",2000);
	set("max_force",2000);

        set_skill("strike", 180);
        set_skill("staff", 180);
        set_skill("dodge", 180);
        set_skill("force", 200);
        set_skill("parry", 200);
        set_skill("literate", 150);
	set_skill("iron-cloth", 200);
	set_skill("magic", 200);
	set_skill("perception",100);

	set_skill("bloodystrike", 180);
	set_skill("cloudstaff", 200);
	set_skill("bolomiduo", 200);
	set_skill("buddhism", 200);
	set_skill("essencemagic", 200);
	set_skill("notracesnow",180);
        set_skill("jin-gang", 200);


	map_skill("strike", "bloodystrike");
        map_skill("staff", "cloudstaff");
        map_skill("force", "bolomiduo");
        map_skill("parry", "cloudstaff");
        map_skill("literate", "buddhism");
        map_skill("iron-cloth", "jin-gang");
        map_skill("magic", "essencemagic");
        map_skill("dodge", "notracesnow");
	prepare_skill("strike","bloodystrike");
	setup();
	carry_object(__DIR__"obj/redcloth")->wear();
        carry_object(__DIR__"obj/9staff")->wield();
}
void reset()
{
        delete_temp("learned");
        set("apprentice_available", 1);
}
void attempt_apprentice(object ob)
{
	if( (string) ob->query("family/family_name") != "大招寺") {
		
		command("say 要加入大招寺可先去拜我的师弟灵空。");
		return;
	}
        else if( !query("apprentice_available") ) {
                command("say 本主持今天已经收了一个弟子，不想再收徒了。");
        }
	else if((int)ob->query_skill("essencemagic",1) < 20 ) {
		command("say 你连八识神通入门工夫都不会，还是先和灵空多学学吧。");
		return ;
	}
	else if( (int) ob->query_skill("buddhism",1) < 180 ||
	    (int) ob->query_skill("bolomiduo",1) < 180 ) {
		command("say 你的大乘佛法和婆萝蜜多心经还不够纯熟。还是多学多钻研的好。");
		return ;
	}
	else 
           call_out("do_recruit", 2, ob);
	return;

}

void do_recruit(object ob)
{
                command("smile");
                command("say 很好，很好，很好。");
                command("recruit " + ob->query("id") );
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "lama");
        add("apprentice_availavble", -1);
}

