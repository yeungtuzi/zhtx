inherit NPC;
int ask_me(object who); 
void create()
{
        object ob;

    set_name("贾人达", ({ "jia renda","jia","renda" }) );
        set("gender", "男性" );
        set("age",26);
        set("long", @TEXT
贾人达是青城派负责接待外宾的工作的。
TEXT
);
        set("per", 24);

        set("combat_exp", 300000);

        set_skill("unarmed",100);
        set_skill("sword", 50);
        set_skill("dodge", 100);
        set_skill("cuixin-zhang",90);
        set_skill("parry",90);
        set_skill("qingcheng-steps" , 80);
        set_skill("pine-sword",80);
        set_skill("force",80);
        map_skill("dodge", "qingcheng-steps");
        map_skill("sword","pine-sword");
        map_skill("parry","pine-sword");
        map_skill("unarmed","cuixin-zhang");

        set("force", 2000);
        set("max_force", 500);
        set("force_factor",100);
	set("inquiry",([
          "food": (: ask_me :),
          "便当": (: ask_me :)
	 ]) );

	set_temp("apply/defense",100);
	set_temp("apply/attack",50);
        create_family("", 19, "弟子");

        setup();
       
        carry_object("/obj/cloth")->wear();
}

void init()
{
        object ob;
        add_action("do_answer","accept");
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }

}
void greeting(object ob)
{
    object teacup;
        if( !ob || environment(ob)!=environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "贾人达对你微笑，和善的对你说：\n  这位" + 
                                RANK_D->query_respect(ob)
                                + "，你好！欢迎来到松风观。请坐！\n");
                        break;
                case 1:
            {
                        say( "贾人达对你微笑，双手捧著茶，\n 说道：这位" +
                                RANK_D->query_respect(ob)
                                + "，你好！欢迎来到松风观。请用茶！\n");
             if ( ob->query_temp("qingcheng/茶") ) 
                 command("smile");
                 else  {
                teacup=new(__DIR__"obj/teacup");
                teacup->move(ob);
                ob->set_temp("qingcheng/茶", 1);
                say ("这是上等猴王茶!您品尝一下。\n");
                   }
            }
                }
}
int do_accept(object food)
{       
        food=new(__DIR__"obj/food");
	message_vision("贾人达给$N一份便当.\n",this_player());
	add("food_trigger",1);
	food->move(this_player());
	return 1;
}
int do_answer(string arg)
{	
	object who;
	if((string)arg=="yes")
       {message_vision("贾人达拿出一份便当.\n",this_player()); 
	call_out("do_accept",1,who,0);
        return 1;}
	else 
	return notify_fail("贾人达说: 好吧，我呆会儿自个送去!\n");
	}
int ask_me(object who)
{       if((int)query("food_trigger")==0)
        { write("贾人达说道: 啊，你不问我还真的忘了，我还要把便当送给人豪呢。但我又走不开。\n");
        write("贾人达说道: 你愿意替我把便当送出去吗?(accept yes or no)\n");
        call_out("do_answer",1,who,0);
	return 1;
	}
	else
        write("贾人达说道:我已经让别人送给 人豪 了.\n");
	return 1;
}
