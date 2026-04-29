//tangmei.c
//written by tang

#include <ansi.h>
inherit NPC;
                         
string *food=({
		GRN "雪山绿果" NOR,
		RED "雪山红果" NOR,
		MAG"莲蓬"NOR,
		MAG"鲤鱼"NOR,
		"臭鸭蛋",
		HIR "麻辣烫" NOR,
		MAG"雪花糕点"NOR,
		MAG"香糕"NOR,
		"宫保鸡丁",
		"水饺",
		"脆皮烤鸭",
		"雪花糕",
		"小花蕊",
		"人参",
		"菠菜粉条",
		"西湖醋鱼",
		"鱼香肉丝",
		"鼋鱼蛋汤",
		"香稣鸡",
		YEL"蟹黄包子"NOR,
		"牛尾",
		HIW"饺子"NOR,		
		});

string ask_me();

void set_food()
{
	remove_call_out("set_food");
	this_object()->set_temp("food",food[random(sizeof(food))]);
	call_out("set_food",600);
}

void create()
{
	set_name("唐梅", ({ "tang mei", "mei" }));
        set("long",@LONG
她是唐门门主唐云的小女儿。平时大家都让她三分,
因为她最喜欢吃零嘴,大家也都经常给她带点好吃的回来.
她最喜欢的人是经常给她好吃的大姐,谁都知道讨好她的最好
办法是给她好吃的,尤其是她没吃过的东西.
LONG
                );
	set("title",HIR "唐门" NOR + GRN "三小姐"NOR);
	set("gender", "女性");
        	set("age", 10);
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
       	set_food();

       	set_temp("apply/armor", 30);

       	set("chat_chance", random(3));
       	set("chat_msg", ({
"唐梅向唐竹扮个鬼脸。  *^G^* \n",
"唐梅说：我要去告诉大哥，说你... \n",
"唐梅说：你好烦哦! 快走开! \n",
"唐梅说：听说乔阴的糖葫芦很好吃，谁能给我买点。嘻! \n",
"唐梅说：上次有人来看剑,给了我一种绿果子,真好吃。嘻! \n",
"唐梅说：你猜我现在最想吃什么? \n",
"唐梅说：谁给我好吃的,我就把他当好朋友.嘻! \n",
"唐梅说：丑八怪! 不要烦我。走开啦! \n",
"唐梅撅著嘴。有点生气的翻过头去，不理你！\n",
"唐梅说: 突然好想吃"+query_temp("food")+"！\n" ,
      		 }) );

        	set("force", 100);
        	set("max_force", 100);
        	set("force_factor", 10);
          	set("combat_exp", 3000);
        	set("score", 500);
		set("book",1);

        	set_skill("force", 30);
        	set_skill("sunv-xinfa", 30);
		set_skill("move", 30);
        	set_skill("dodge", 30);
        	set_skill("taxue-wuhen", 30);
		set_skill("strike", 30);
        	set_skill("tangmen-duzhang", 30);
        	set_skill("parry", 30);
        	set_skill("sword", 30);
        	set_skill("yuenv-jian", 30);
		set_skill("throwing",30);
		set_skill("tiannv-sanhua",30);
               	set_skill("literate", 60); 
		set_skill("dugong",40);

        	map_skill("force", "sunv-xinfa");
        	map_skill("dodge", "taxue-wuhen");
		map_skill("move", "taxue-wuhen");
		map_skill("strike", "tangmen-duzhang");
        	map_skill("parry", "yuenv-jian");
        	map_skill("sword", "yuenv-jian"); 
		map_skill("throwing", "tiannv-sanhua");

        	prepare_skill("strike", "tangmen-duzhang");

		set("inquiry",([
		"钥匙"	:(:ask_me:),
			]));	
        	create_family("唐门", 5, "女弟子");

        	setup();
        	carry_object(__DIR__"obj/skirt")->wear();
}

int reset()
{
	set_food();
}                  
     
string ask_me()
{
	object who;
    	who=this_player();  

	if ( who->query("family/family_name") != "唐门" )
	{                                      
		command("angry");
            	return "你是谁?怎么我没见过你?爹爹不许我和不认识的人说话。\n";
	}             

	if ( who->query("family/generation") > 5 )
	{                                      
		command("walkby");
            	return "我们正玩呢,晚辈小孩子别来烦我。\n";
	}             
                                                 
	if( who->query("marks/tangmei") < 20 )
	{
		command("angry");
		return CYN"“我干吗要告诉你啊,我只告诉我的好朋友。”\n"NOR;
	}
	who->set_temp("marks/tangmei_ok",1);
	return CYN"“你对我真好,今天给我带了什么好吃的呀。”\n"NOR;
            	
}
        
int accept_object(object who, object ob)
{
     	object me,*obs,partner;
     	string objname;
     	int i;

     	me = this_player();          
     	if( userp(ob) )
     	{
     		command("kick "+me->query("id"));
     		who->add("marks/tangmei",-100);  
     		return 0;
     	}
     	
     	obs = all_inventory(environment(me));
     	i = sizeof(obs);
     	while(i--)
     	{
     		if( userp(obs[i]) && obs[i]->query_temp("marks/changsheng-getgold") && obs[i]->query_temp("marks/changsheng-getsword"))
		{
			partner = obs[i];
			i = 99999999;
			break;
		}     		
     	}

     	objname = (string)ob->name();

       	if ( member_array(objname,food) == -1 )  
       	{
		command("smile");
       		say ("这要送给我啊?! 怎麽好意思!谢谢你。\n");
       		command("xixi");       
       		destruct(ob);
       		return 1;
       	}
        	
	if( i==99999999 && who->query_temp("marks/tangmei_ok") && objname == query_temp("food") )  
	{
            		tell_object(me, "唐梅很开心的拿起"+objname+"吃!\n");
            		tell_object(me, "“现在我们是好伙伴啦!”， 她小声的在你耳边说：\n");
            		tell_object(me, "『 我告诉你一个秘密：唐竹从大哥那拿了一把钥匙!』\n");
			who->set_temp("marks/唐3",1);
			partner->delete_temp("marks/changsheng-getgold");
			partner->delete_temp("marks/changsheng-getsword");			
			who->delete_temp("marks/tangmei_ok");
			destruct(ob);
			return 1;
	}                                      
	command("face");
	if( query("book")>0 && !me->query_temp("marsk/throwbook") )
	{
		ob=new(__DIR__"obj/throw_book");
		ob->move(me);	
		me->set_temp("marsk/throwbook",1);      
		me->delete_temp("marks/唐2");
		set("book",0);
		message_vision("唐梅给$N一本书。\n",me);
	}		                                     
	command("whisper "+who->query("id")+" 你真好.");
	who->add("marks/tangmei",1); 
	destruct(ob);
	return 1;
}

int receive_damage(string type,int amount,object who)
{                                         
	who->add("marks/tangmei",-amount/20);
	return ::receive_damage(type,amount,who);
}
