// popo.c
inherit NPC;

void init();
int do_ling(string);
string ask_me();
void create()
{
        set_name("孙婆婆", ({
                "sun popo",
                "sun",
                "popo",
        }));
	set("title","古墓派总管");
        set("long",
                "她是一位老婆婆，脸上布满皱纹。\n"
        );
        set("gender", "女性");
        set("attitude", "friendly");
        
        set("age", 75);
        set("shen_type", 1);
        set("str", 21);
        set("int", 25);      
        set("con", 20);
        set("dex", 25);
        set("max_kee", 1000);
        set("max_gin", 500);
        set("force", 1000);
        set("max_force", 1000);
        set("force_factor", 70);
        set("combat_exp", 150000);
        set("score", 10000);
        set_skill("force", 100);
        set_skill("yunu-xinfa", 100);
        set_skill("dodge", 100);
        set_skill("xianyun", 100);
        set_skill("meinu-quan", 100);
        set_skill("cuff", 100);
        set_skill("parry", 100);
        set_skill("zhinv-zhen", 120);
        set_skill("throwing", 120);        
 //       set_skill("mahayana", 100);
        set_skill("literate", 100);
        map_skill("force", "yunu-xinfa");
        map_skill("dodge", "xianyun");
        map_skill("cuff", "meinu-quan");
        map_skill("parry", "meinu-quan");
        map_skill("throwing", "zhinv-zhen");        
        prepare_skill("cuff", "meinu-quan");
/*
	 set("inquiry", ([
                "出墓" : (: ask_me :),
           
        ]));
*/        
  //      create_family("古墓派", , "弟子");
        setup();
        carry_object("/d/gumu/obj/yufengzhen")->wield();
//        carry_object("/d/gumu/obj/cloth")->wear();
}

void init()
{
//   add_action("do_ling","ling");
}                               


int do_ling(string arg)
{
 object ob = this_object();
 object me = this_player();
 object obj;
 if(!arg || (arg != "zhujian" && arg != "changbian"))
    return notify_fail("你要领什么？\n"); 
 
 if( arg == "zhujian")
    { 
      if(objectp(present("zhujian", this_player())) ) 
         return notify_fail("你已有了，还领什么？\n");
      command("say 好吧，就给你一把竹剑。\n");
      message_vision("$N交给$n一把竹剑。\n", ob, me);
      obj=new(__DIR__"obj/zhujian");
    }  
 if( arg == "changbian")
    { 
      if(objectp(present("changbian", this_player())) ) 
         return notify_fail("你已有了，还领什么？\n");
      command("say 好吧，就给你一把长鞭。\n");
      message_vision("$N交给$n一把长鞭。\n", ob, me);
      obj=new(__DIR__"obj/changbian");
    }                          
  obj->move(me);
  return 1;
}
string ask_me()
{	 mapping fam;
        object me=this_player();
        object ob;
	 if (!(fam = this_player()->query("family")) || fam["family_name"] != "古墓派")
      		{  
		if(me->query("max_force")<1000){
		message_vision("孙婆婆说道“好吧，我就带你出古墓吧。”\n",me);     
	me->move("/d/gumu/duanlongshi");  
	 return "想不到外人对我古墓派还也有兴趣。";}
		else
		return"你又不是不能出墓，何必麻烦老妪呢。";
		}
 	else
	{
		if (me->query("age")<15)
		{
	
		return"江湖险恶，你年龄太小，还是不要出去为好。";
		}
	message_vision("孙婆婆说道“好吧，我就带你出古墓吧。”\n",me);     
	me->move("/d/gumu/duanlongshi");  
	return"好了，我要回去了。";
	}

}