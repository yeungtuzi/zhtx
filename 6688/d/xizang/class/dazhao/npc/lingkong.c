// /d/xizang/class/dazhao/npc/lingkong.c

inherit "/u/z/zephyr/revengenpc.c";
inherit F_MASTER;

void create()
{
	set_name("灵空上人", ({ "master lingkong", "lingkong","master" }) );
	set("gender", "男性" );
	set("age", 51);
	set("int", 29);
        set("apprentice_available", 10);
        create_family("大招寺", 33, "弟子");
	set("long",
		"他是班禅大师的得意弟子之一,许多师弟妹是由他代为传授功夫\n");
	set("inquiry", ([
		"舍利子": "嗯....舍利子.....在舍利塔里。\n",
		"普松": "普松在大招寺的木屋里。",
	]) );
        set("combat_exp", 1000000);
        set("score", 10000);
	set("shen", -2000);
	set("force", 4000);
	set("max_force", 2000);
	set("mana", 4000);
	set("max_mana", 2000);
	set("atman", 4000);
	set("max_atman", 2000);
        set_skill("unarmed", 100);
	set_skill("bloodystrike", 220);
        set_skill("force", 220);
        set_skill("parry", 200);
	set_skill("staff", 220);
	set_skill("cloudstaff", 240);
        set_skill("literate", 150);
	set_skill("magic", 150);
	set_skill("bolomiduo", 240);
	set_skill("zang-buddhi", 240);
	set_skill("iron-cloth", 200);
	set_skill("jin-gang", 180);
//	set_skill("shield", 340);
	set_skill("essencemagic", 30);

        map_skill("force", "bolomiduo");
	map_skill("unarmed", "bloodystrike");
	map_skill("magic", "essencemagic");
	map_skill("staff", "cloudstaff");
	map_skill("parry", "cloudstaff");
	map_skill("iron-cloth", "jin-gang");
	
	setup();
	carry_object("/class/lama/cassock")->wear();
	carry_object("/class/lama/obj/zijinzhang")->wield();
}

void reset()
{
        delete_temp("learned");
        set("apprentice_available", 10);
}

void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say 慢著，一个一个来。");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say 我现在累了，不想再收徒了。");
        }
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
