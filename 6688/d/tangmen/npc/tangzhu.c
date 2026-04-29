//tangzhu.c
//written by tang

#include <ansi.h>
inherit NPC;
                         
string *food=({
//		GRN "雪山绿果" NOR
		RED "雪山红果" NOR		
		});
string ask_me();

void create()
{
	set_name("唐竹", ({ "tang zhu", "zhu" }));
        	set("long", "他是唐门门主唐云的小儿子，经常想些鬼主意捉弄他妹妹唐梅。\n");
	set("title",HIR "唐门" NOR + GRN "小少爷"NOR);
	set("gender", "男性");
        	set("age", 12);
        	set("attitude", "friendly");
        	set("shen_type", -1);

	set("str", 15 + random(16));
	set("cps", 15 + random(16));
	set("int", 15 + random(16));
	set("cor", 15 + random(16));
	set("con", 15 + random(16));
	set("spi", 15 + random(16));
	set("per", 15 + random(16));
	set("kar", 15 + random(16));
                                        
	set("kee",300);
        	set("max_kee", 300);
	set("gin",200);
        	set("max_gin", 200);
	set("sen",200);
	set("max_sen", 200);
	set("atman", 100);
	set("max_atman", 100);
	set("mana", 100);
	set("max_mana", 100);

	set("chat_chance_combat", 100);
        	set("chat_msg_combat", ({
	 	(: perform_action , "throwing.mantian" :)
	        }) );

	set_temp("apply/armor", 30);

         	set("chat_chance", 7);
       
	set("chat_msg", ({
"顽皮的唐竹向你扮个鬼脸。  *^G^* \n",
"唐竹说：长生剑客退隐后，所用佩剑藏在藏剑阁! \n",
"唐竹说：京城的糖人比糖葫芦还好吃! \n",
"唐竹说：你告诉大哥，我就不跟你玩啦! \n",
"唐竹说：其实最好吃的还是上次叔叔带来的红果子。！好想再吃。\n",
"唐竹嘟著嘴。有点生气的翻过头去，不理唐梅！\n"
       }) );

        	set("force", 100);
        	set("max_force", 100);
        	set("force_factor", 10);
          	set("combat_exp", 3000);
        	set("score", 500);

        	set_skill("force", 30);
        	set_skill("tangmen-xinfa", 30);
	set_skill("move", 30);
        	set_skill("dodge", 30);
        	set_skill("taxue-wuhen", 30);
	set_skill("strike", 30);
        	set_skill("tangmen-duzhang", 30);
        	set_skill("parry", 30);
        	set_skill("sword", 30);
        	set_skill("tangshi-jian", 30);
	set_skill("throwing",30);
	set_skill("mantian-huayu",30);
               set_skill("literate", 60);
	set_skill("dugong", 40);

        	map_skill("force", "tangmen-xinfa");
        	map_skill("dodge", "taxue-wuhen");               
	map_skill("move", "taxue-wuhen");
	map_skill("strike", "tangmen-duzhang");
        	map_skill("parry", "tangshi-jian");
        	map_skill("sword", "tangshi-jian"); 
	map_skill("throwing", "mantian-huayu");

        	prepare_skill("strike", "tangmen-duzhang");

	set("inquiry",([
		"钥匙"	:(:ask_me:),
			]));	
        	create_family("唐门", 5, "弟子");

        	setup();
        	carry_object(__DIR__"obj/jinyi")->wear();
}
                       
string ask_me()
{
	object who;
    	who=this_player();  

	if ( who->query_temp("marks/唐3")==1 )
	{
		return CYN"“我也要吃点心。”\n"NOR;
	}             
                                                  
	command("xixi");
            	return "我不知道你在问什么。\n";
}
        
int accept_object(object who, object ob)
{
     	object me,key;
     	string objname;

     	me = this_player();
     	objname = (string)ob->name();

        	if ( objname != food[random(sizeof(food))] )  
           	{
		command("smile");
            		say ("这要送给我啊?! 怎麽好意思!谢谢你。\n");
           		command("xixi");
             		return 1;
          	}
        	
	if( who->query_temp("marks/唐3") )  
	{
            		tell_object(me, "唐竹很开心的拿起"+objname+"吃!\n");
            		tell_object(me, "满怀感激的谢谢你! 他小声的在你耳边说：\n");
            		tell_object(me, "『 我把从大哥那拿的钥匙给你!』\n");
            		who->delete_temp("marks/唐3"); 
            		who->set_temp("marks/changsheng-ok",1);
			key=new(__DIR__"obj/key");
			key->move(me);
			return 1;
	}                                      
	command("face");
	return 1;
}

void init()
{
}
