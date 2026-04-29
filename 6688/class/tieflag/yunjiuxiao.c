inherit NPC;
inherit F_MASTER;
inherit F_QUEST;

void re_rank(object);
void in_combat();

void create()
{
        set_name("云九霄", ({ "yun jiuxiao", "yun","master" }) );
        set("gender", "男性" );
        set("age", 52);
        set("int",100);
	set("cor", 100);
	set("cps", 100);
	set("title","铁血大旗门长老");

        set("apprentice_available", 50);
        create_family("铁血大旗门", 7, "长老");
        set("long","他是铁血大旗门的掌刑长老，最是严厉不过。\n");

        set("max_gin", 1350);
        set("max_kee", 3000);
        set("max_sen", 1350);

        set("max_force", 3000);
        set("force", 6000);
	set("force_factor",200);
 
        set("attitude", "peaceful");
        set("combat_exp", 3000000);

        set_skill("dormancy",200);
        set_skill("cuff", 200);
        set_skill("sword", 200);
        set_skill("force", 200);
        set_skill("parry", 200);
        set_skill("literate", 150);
        set_skill("dodge", 200);
        set_skill("ill-quan", 200);
        set_skill("fy-sword", 200);
        set_skill("tie-steps", 200);
        set_skill("yunhai-force", 200);


        map_skill("cuff", "ill-quan");
        map_skill("sword", "fy-sword");
        map_skill("force", "yunhai-force");
        map_skill("parry", "fy-sword");
        map_skill("dodge", "tie-steps");
        prepare_skill("cuff", "ill-quan");

	set("chat_chance_combat",90);
        set("chat_msg_combat", ({
              (: in_combat :),
        }) );

        setup();
        carry_object("obj/cloth")->wear();
	carry_object("/d/tieflag/obj/cmsword")->wield();
}

void reset()
{
        delete_temp("learned");
        set("apprentice_available", 20);
}
void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say 慢著，一个一个来。");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say 本人今天已经收了二十个弟子，不想再收徒了。");
        }
}
void do_recruit(object ob)
{
        if( ob->query("betrayer") )
        { 
		command("say 你多次背信弃义，叛出师门，我岂能容你！");
        }
         else if( ob->query_skill("jiayiforce",1) < 50 )
	{
		command("say 你的嫁衣神功等级不够，不能拜师。");
	}
	else
	{
		command("say 入我铁血门下，必须改从我姓，你可愿意(Accept yes/no)？");
		ob->set_temp("apprentice_me",1);
        }
}

int do_accept(string arg)
{
	object me;
	string cname;

	me = this_player();
	if( !(me->query_temp("apprentice_me")) )
		return 0;

	if( !arg || arg != "yes" )
	{
		command("heng");
		return 1;
	}		

        cname = me->name();
        if( sizeof(cname) > 2 )
                me->set("name","云"+cname[2..sizeof(cname)-1]);
        else
                me->set("name","云"+cname);

	me->delete_temp("apprentice_me");
        command("say 入我铁血门下，即为至亲兄弟姐妹，你日后必有大成！");
        command("smile");
        command("recruit " + me->query("id") );
	return 1;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "tieflag");
//        re_rank(ob);
        add("apprentice_availavble", -1);
}

void init()
{
   ::init();
   add_action("give_quest", "quest");
   add_action("do_accept", "accept");
}

void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 3200 ) {
                student->set("title","铁血大旗门弟子");
                return ;
        } else if ( exp <= 12800 ) {
                student->set("title","铁血大旗门小侠");
                return ;
        } else if ( exp <= 51200 ) {
                student->set("title","铁血大旗门少侠");
                return ;
        } else if ( exp <= 153600 ) {
                student->set("title","铁血大旗门大侠");
                return ;
        } else if ( exp <= 345600 ) {
                student->set("title","铁血大旗门奇侠");
                return ;
        } else if ( exp <= 518700 ) {
                student->set("title","铁血大旗门元老");
                return ;
        } else if ( exp <= 8624400 ) {
                student->set("title","铁血大旗门长老");
                return ;
        } else
                student->set("title","铁血大旗门副掌门");
                return ;
}

// check if bribe is valid
int valid_bribe(object who,int val) {
        message_vision( (this_object())->query("name")+"向$N一甩袍袖，说道： 什么，你想贿赂我吗？！\n",who);
        return(0);
}

// called when not finish the task
int quest_punish(object who) {
        message_vision( (this_object())->query("name")+"向$N一甩袍袖，说道： 真笨，你好好学学功夫再要任务吧！\n" ,who);
    who->set("quest",0);
    return(0);
}

void in_combat()
{
	int hurt,force_fac;

	if( query("force_factor") < 220 )
		command("exert swat");

        if( query("eff_kee")<query("max_kee")*65/100)     
        {
                force_fac = query("force_factor");
                if(is_fighting()) command("halt");
                hurt = query("max_kee")-query("eff_kee");
                hurt /= 100;
                while( hurt-- )
                        command("exert heal");
                set("force_factor",force_fac);
        }         

        if(query("sen")<(query("eff_sen")*70/100))
                command("exert refresh");
        if(query("kee")<(query("eff_kee")*70/100))
                command("exert recover");
        if(query("gin")<(query("eff_gin")*70/100))
                command("exert regenerate");

}


