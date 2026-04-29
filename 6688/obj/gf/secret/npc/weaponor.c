/* weaponor.c*/
#include <ansi.h>

inherit NPC;
inherit F_VENDOR;
object wea;

void talk_weapon(object who, int stage);
void talk_pu(object who, int stage);
void talk_find(object who, int stage);

void talk_blade(object who, int stage);
void talk_qixiu(object who, int stage);
void talk_zhantie(object who, int stage);
void talk_pocan(object who, int stage);
void talk_lingkong(object who, int stage);

void ask_blade();
void ask_qixiu();
void ask_zhantie();
void ask_pocan();
void ask_lingkong();

void ask_weapon();
void ask_pu();
void ask_find();

int allow_weapon();
int allow_pu();
int allow_find();

int allow_blade();
int allow_qixiu();
int allow_zhantie();
int allow_pocan();
int allow_lingkong();

int reward(object ob);

string *msg_weapon=({
YEL"兵器贩子说道：“老夫生平酷爱收集天下神兵利器，所藏甚丰。”\n"NOR,
YEL"说道这里，兵器贩子脸上流露出一丝微笑。\n"NOR,
YEL"兵器贩子对你点点头，说道：“这位小朋友，这些事情，你是怎么会知道的呢？”\n"NOR,
CYN"你忙说道：“是隔壁木道人告诉我你在这里的。”\n"NOR,
YEL"“哈哈哈哈哈哈哈哈哈哈哈哈哈”兵器贩子大笑。\n"NOR,
YEL"“这个老家伙，居然这么随便就把我的行踪出卖出去了”\n"NOR,
CYN"你大气都不敢出，但是看上去他并不是生气的样子。\n"NOR,
CYN"你向他解释，是如此这般，你才能从木道人那里得到他的消息。\n"NOR,
YEL"兵器贩子点点头，说道：“嗯，原来如此。好吧，小朋友，如此说来，你我算是有缘。你找到我，有什么事情吗？”\n"NOR,
});

string *msg_pu=({
YEL"兵器贩子言道：我年少之时曾经收集到当今世上这五柄神兵，\n"NOR,
YEL"斩铁剑、出跸刀、七修剑、刈鹿刀和灵空剑。\n"NOR,
YEL"为这五柄神兵，我写了一本小册子，名为《纵横兵器谱》\n"NOR,
YEL"若干年前，我在天目山玉琴楼闭关修练，不料...\n"NOR,
YEL"有贼子不晓得从哪儿得知了我收藏兵器之处，趁我不在，将我那五柄最为珍视的神兵盗走。可恨！！\n"NOR,
CYN"说到这里，兵器贩子眼中放出惊人的光芒...\n"NOR,
CYN"你大气都不敢出...\n"NOR,
YEL"“七年前我出关之后，那些贼子早已经死尽，那五柄神兵也已经各有其主”\n"NOR,
YEL"“唉...”叹毕，兵器贩子不再言语。\n"NOR,
});

string *msg_find=({
YEL"兵器贩子盯着你看了一会，说道：你可当真？\n"NOR,
CYN"你信誓旦旦发誓道：”我一定帮你把这五柄兵器找回。如违此言，就如此剑！”\n"NOR,
CYN"你从腰间抽出一柄长剑，屈起右手中指，当剑身中间轻轻一弹，铮的一声，长剑拦腰而断。\n"NOR,
YEL"“好！”兵器贩子点点头，如果真能帮我找回我的兵器，不胜感激！\n"NOR,
YEL"兵器贩子沉吟半晌，缓缓说道：现在这些兵器已经流落武林各处，”\n"NOR,
YEL"“拥有者都是天下武林大豪，你试着去打听一下吧！”\n"NOR,
YEL"兵器贩子拍拍你的肩膀，你只觉一股暖流流遍你的全身，如浴温泉。\n"NOR,
CYN"你抱拳道：就此告辞。\n"NOR,
});
string *msg_blade=({
YEL"兵器贩子说道：“此刀乃春秋战国时铸剑名徐夫人之嫡裔徐鲁子耗尽毕生精力铸成。”\n"NOR,
YEL"“其名取意“秦失其鹿，天下共逐，唯胜者得鹿而刈之。”\n"NOR,
YEL"”此刀色泽淡青，杀人不见血迹。”\n"NOR,
});
string *msg_qixiu=({
YEL"兵器贩子说道：“为当年七修真人镇山之宝，属上古降魔利器。该剑既出，能幻出道道”\n"NOR,
YEL"“金白之光，光到之处，杀伤力极强。”\n"NOR,
YEL"”七修真人后将此剑传与杜铁池。杜铁池得此宝后，降妖伏魔，大建奇功，后杜铁池成为七修门掌门。”\n"NOR,
});
string *msg_zhantie=({
YEL"兵器贩子说道：“此乃上古神物，吾不敢多言。”\n"NOR,
});
string *msg_pocan=({
YEL"兵器贩子说道：“名刀出跸，乃一柄黄杨木雕的弯刀，无鞘，刀身长三尺半，上面”\n"NOR,
YEL"“雕有美人出跸图，图上人物凡143，马匹109，车辆16，云麾、车盖、仪仗等均历”\n"NOR,
YEL"”历可数，据说这些东西如果放为原大，那就要前后排上十来里长，如果化成图画，”\n"NOR,
YEL"”裱上手卷，也得绵延十数丈。画与雕刻都出自名家，形态逼真神情生动。”\n"NOR,
});
string *msg_lingkong=({
YEL"兵器贩子说道：“此剑乃由铸剑大师邵空子炼成，未几邵大师请一名宿相此宝剑，那名宿却认为是一柄凶剑，”\n"NOR,
YEL"“剑身上光纹四射如火，主大凶，佩带都必定招致不详，甚至会有家破人亡之祸。”\n"NOR,
});


void create()
{
        set_name("兵器贩子", ({ "weaponor" }) );
        set("title", "兵器屋");
        set("gender", "男性" );
        set("age", 48);
        set("long", "卖兵器的是个中年人，脸上看不出什么表情。\n");
        set("combat_exp", 20000);
        set("attitude", "friendly");
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("sword", 80);
		set("count",1);
        set("inquiry", ([
                "兵器屋" : "本店专卖各种兵器,防具.", 
                "木道人" : "十年前机缘巧合我救过他一命。", 
                "神兵利器"    : (: ask_weapon :),
                "刈鹿刀"    : (: ask_blade :),
                "七修剑"    : (: ask_qixiu :),
                "斩铁剑"    : (: ask_zhantie :),
                "出跸刀"    : (: ask_pocan :),
                "灵空剑"    : (: ask_lingkong :),
                "兵器谱"    : (: ask_pu :),
                "纵横兵器谱"    : (: ask_pu :),
                "找回兵器"    : (: ask_find :),
        ]) );

        set("vendor_goods", ([
                "/obj/weapon/whip":5,
                "/obj/weapon/longsword":5,
                "/obj/weapon/dart":5,
                "/obj/weapon/shield":5,
//              "/obj/weapon/sixhammer":5,
 //             "/obj/weapon/thin_sword":5,
                "/obj/weapon/dagger.c":5,
               
        ]) );
     setup();
     add_money("silver", 5);
     add_money("coin", 300);
     carry_object("/obj/cloth")->wear();
     carry_object("/obj/weapon/longsword")->wield();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
		{
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");


}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(4) ) {
                case 0:
                        say( "兵器贩子道：这位"
                                + RANK_D->query_respect(ob)
                                + "，自个儿挑一件称手的兵器吧\n");
                        break;
                case 1:
                        say( "兵器贩子突然间出了神，非常的深沉,使你捉摸不透.\n");
                        break;
        }
}


//talk_functions
void talk_blade(object who, int stage)
{                       
	tell_object(who, msg_blade[stage]);
	if ( !who || environment(who) != environment() )	return;
	
	if( ++stage < sizeof(msg_blade) ) 
	{
		call_out( "talk_blade", 1, who, stage );
		return;
	}
	remove_call_out("allow_blade");
	call_out("allow_blade", 1);

	return;
}
void talk_qixiu(object who, int stage)
{                       
	tell_object(who, msg_qixiu[stage]);
	if ( !who || environment(who) != environment() )	return;
	
	if( ++stage < sizeof(msg_qixiu) ) 
	{
		call_out( "talk_qixiu", 1, who, stage );
		return;
	}
	remove_call_out("allow_qixiu");
	call_out("allow_qixiu", 1);

	return;
}
void talk_zhantie(object who, int stage)
{                       
	tell_object(who, msg_zhantie[stage]);
	if ( !who || environment(who) != environment() )	return;
	
	if( ++stage < sizeof(msg_zhantie) ) 
	{
		call_out( "talk_zhantie", 1, who, stage );
		return;
	}
	remove_call_out("allow_zhantie");
	call_out("allow_zhantie", 1);

	return;
}
void talk_pocan(object who, int stage)
{                       
	tell_object(who, msg_pocan[stage]);
	if ( !who || environment(who) != environment() )	return;
	
	if( ++stage < sizeof(msg_pocan) ) 
	{
		call_out( "talk_pocan", 1, who, stage );
		return;
	}
	remove_call_out("allow_pocan");
	call_out("allow_pocan", 1);

	return;
}
void talk_lingkong(object who, int stage)
{                       
	tell_object(who, msg_lingkong[stage]);
	if ( !who || environment(who) != environment() )	return;
	
	if( ++stage < sizeof(msg_lingkong) ) 
	{
		call_out( "talk_lingkong", 1, who, stage );
		return;
	}
	remove_call_out("allow_lingkong");
	call_out("allow_lingkong", 1);

	return;
}
void talk_weapon(object who, int stage)
{                       
	tell_object(who, msg_weapon[stage]);
	if ( !who || environment(who) != environment() )	return;
	
	if( ++stage < sizeof(msg_weapon) ) 
	{
		call_out( "talk_weapon", 1, who, stage );
		return;
	}
	remove_call_out("allow_weapon");
	call_out("allow_weapon", 1);

	return;
}
void talk_pu(object who, int stage)
{                       
	tell_object(who, msg_pu[stage]);
	if ( !who || environment(who) != environment() )	return;
	
	if( ++stage < sizeof(msg_pu) ) 
	{
		call_out( "talk_pu", 2, who, stage );
		return;
	} 
	remove_call_out("allow_pu");
	call_out("allow_pu", 1);
	return;
}
void talk_find(object who, int stage)
{                       
	tell_object(who, msg_find[stage]);
	if ( !who || environment(who) != environment() )	return;
	
	if( ++stage < sizeof(msg_find) ) 
	{
		if (stage==3)
		{
			call_out ("dest_sword",1);
		}
		call_out( "talk_find", 3, who, stage );
		return;
	} 
	remove_call_out("allow_find");
	call_out("allow_find", 1);
	return;
}



//ask_functions

void ask_blade()
{
	if( query("count")==0 )
	{
        command("?");
		add("count",-1);
	    return; 
	}
	if( query("count")<0 )
	{
	    return; 
	}

	if (this_player()->query_temp("weaponor3"))
	{
		command("sigh");
		command("look "+this_player()->query("id"));
		remove_call_out("talk_blade");
		call_out("talk_blade",2,this_player(),0);    
		add("count",-1);
	}
	command("sigh");
	return;

}

void ask_qixiu()
{
	if( query("count")==0 )
	{
        command("?");
		add("count",-1);
	    return; 
	}
	if( query("count")<0 )
	{
	    return; 
	}

	if (this_player()->query_temp("weaponor3"))
	{
		command("sigh");
		command("look "+this_player()->query("id"));
		remove_call_out("talk_qixiu");
		call_out("talk_qixiu",3,this_player(),0);    
		add("count",-1);
	}
	command("sigh");
	return;

}

void ask_zhantie()
{
	if( query("count")==0 )
	{
        command("?");
		add("count",-1);
	    return; 
	}
	if( query("count")<0 )
	{
	    return; 
	}

	if (this_player()->query_temp("weaponor3"))
	{
		command("sigh");
		command("look "+this_player()->query("id"));
		remove_call_out("talk_zhantie");
		call_out("talk_zhantie",3,this_player(),0);    
		add("count",-1);
	}
	command("sigh");
	return;

}

void ask_pocan()
{
	if( query("count")==0 )
	{
        command("?");
		add("count",-1);
	    return; 
	}
	if( query("count")<0 )
	{
	    return; 
	}

	if (this_player()->query_temp("weaponor3"))
	{
		command("sigh");
		command("look "+this_player()->query("id"));
		remove_call_out("talk_pocan");
		call_out("talk_pocan",3,this_player(),0);    
		add("count",-1);
	}
	command("sigh");
	return;

}

void ask_lingkong()
{
	if( query("count")==0 )
	{
        command("?");
		add("count",-1);
	    return; 
	}
	if( query("count")<0 )
	{
	    return; 
	}

	if (this_player()->query_temp("weaponor3"))
	{
		command("sigh");
		command("look "+this_player()->query("id"));
		remove_call_out("talk_lingkong");
		call_out("talk_lingkong",3,this_player(),0);    
		add("count",-1);
	}
	command("sigh");
	return;

}

void ask_weapon()
{	
	if( query("count")==0 )
	{
        command("?");
		add("count",-1);
	    return; 
	}
	if( query("count")<0 )
	{
	    return; 
	}

	if (this_player()->query_temp("weaponor2"))
	{
		command("haha "+this_player()->query("id"));
		remove_call_out("talk_weapon");
		call_out("talk_weapon",2,this_player(),0);    
		add("count",-1);
	}
	return;
}


void ask_pu()
{
	if( !this_player()->query_temp("weaponor2") ) return;
	if( query("count")==0 )
	{
        command("?");
		add("count",-1);
	    return; 
	}
	if( query("count")<0 )
	{
	    return; 
	}

	if ( this_player()->query_temp("weaponor/blade") && this_player()->query_temp("weaponor/qixiu") && this_player()->query_temp("weaponor/zhantie") && this_player()->query_temp("weaponor/pocan") && this_player()->query_temp("weaponor/lingkong"))
	{
		command("sigh");
		message_vision(CYN"兵器贩子望着远方沉默了半晌...\n"NOR,this_player());
		remove_call_out("talk_pu");
		call_out("talk_pu",3,this_player(),0);    
		add("count",-1);
	}
	else command("say 很久以前的事情了。书里面所记载的兵器再也没人能数的出来了，还提它干吗。");
	this_player()->set_temp("weaponor3",1);
	return;
}

void ask_find()
{
	if( query("count")==0 )
	{
        command("?");
		add("count",-1);
	    return; 
	}
	if( query("count")<0 )
	{
	    return; 
	}
	if (this_player()->query_temp("weaponor4"))
	{
		message_vision(YEL"兵器贩子眼中流露出一丝不信任的眼光...\n"NOR,this_player());
		command("look "+this_player()->query("id"));
		command("hmm");
		remove_call_out("talk_find");
		call_out("talk_find",5,this_player(),0);
		add("count",-1);
	}
	return;
}



//allow_functions
int allow_weapon()
{
	this_player()->set_temp("weaponor3",1);
	if (wizardp(this_player())) tell_object(this_player(),"你现在可以问他关于各个兵器的事情\n");
	set("count",1);
	return 1;
}

int allow_pu()
{
	this_player()->set_temp("weaponor4",1);
	if (wizardp(this_player())) tell_object(this_player(),"you have access to ask_find now\n");
	set("count",1);
	return 1;
}

int allow_find()
{
	this_player()->set_temp("weaponor5",1);
	if (wizardp(this_player())) tell_object(this_player(),"you have access to search for the weapons now\n");
	set("count",1);
	return 1;
}


int allow_blade()
{
	this_player()->set_temp("weaponor/blade",1);
	if (wizardp(this_player())) tell_object(this_player(),"you have access to weaponor/blade\n");
	set("count",1);
	return 1;
}


int allow_qixiu()
{
	this_player()->set_temp("weaponor/qixiu",1);
	if (wizardp(this_player())) tell_object(this_player(),"you have access to weaponor/qixiu\n");
	set("count",1);
	return 1;
}


int allow_zhantie()
{
	this_player()->set_temp("weaponor/zhantie",1);
	if (wizardp(this_player())) tell_object(this_player(),"you have access to weaponor/zhantie\n");
	set("count",1);
	return 1;
}


int allow_pocan()
{
	this_player()->set_temp("weaponor/pocan",1);
	if (wizardp(this_player())) tell_object(this_player(),"you have access to weaponor/pocan\n");
	set("count",1);
	return 1;
}

int allow_lingkong()
{
	this_player()->set_temp("weaponor/lingkong",1);
	if (wizardp(this_player())) tell_object(this_player(),"you have access to weaponor/lingkong\n");
	set("count",1);
	return 1;
}



int dest_sword()
{
	command("hmm");
	wea=new("/obj/weapon/changjian");
	wea->move(environment());
	wea->set("name", "断成两截的" + wea->query("name"));
	wea->set("value", 0);
	wea->set("weapon_prop", 0);
	wea->set("long", wea->query("long")+"现在却已经断成了两截。\n");
}

int accept_object(object ob, object obj)
{

	if (!ob->query_temp("weaponor5"))
	{
		command("say 你我素昧平生，在下不敢承受。\n");
		return 0;
	}

	if ((obj->query("id")=="zhantie jian")&&(ob->query_temp("weaponor5")))
	{ 
		command("say 哎呀！这正是上古神兵，斩铁剑啊！\n");
		command("say 多谢这位英雄！\n");
		command("bow");
		ob->set_temp("find_zhantiejian",1);
		if ( ob->query_temp("find_zhantiejian") && ob->query_temp("find_qixiujian") && ob->query_temp("find_yiludao") && ob->query_temp("find_lingkongjian") && ob->query_temp("find_chubidao") )
		{
			call_out("reward", 1, ob);
		}
		destruct(obj);
		return 1;
	}

	if ((obj->query("id")=="qixiu jian")&&(ob->query_temp("weaponor5")))
	{ 
		command("say 哎呀！这正是上古降魔利器，七修剑啊！\n");
		command("say 多谢这位英雄！\n");
		command("bow");
		ob->set_temp("find_qixiujian",1);
		if ( ob->query_temp("find_zhantiejian") && ob->query_temp("find_qixiujian") && ob->query_temp("find_yiludao") && ob->query_temp("find_lingkongjian") && ob->query_temp("find_chubidao") )
		{
			call_out("reward", 1, ob);
		}
		destruct(obj);
		return 1;
	}


	if ((obj->query("id")=="lingkong jian")&&(ob->query_temp("weaponor5")))
	{ 
		command("say 哎呀！这正是邵空子所炼神兵利器，灵空剑啊！\n");
		command("say 多谢这位英雄！\n");
		command("bow");
		ob->set_temp("find_lingkongjian",1);
		if ( ob->query_temp("find_zhantiejian") && ob->query_temp("find_qixiujian") && ob->query_temp("find_yiludao") && ob->query_temp("find_lingkongjian") && ob->query_temp("find_chubidao") )
		{
			call_out("reward", 1, ob);
		}
		destruct(obj);
		return 1;
	}


	if ((obj->query("id")=="po chubi dao")&&(ob->query_temp("weaponor5")))
	{ 
		command("say 啊，名刀出跸！怎么破成了两片呢？\n");
		command("?");
		message_vision("$N向兵器贩子详细的解释了找寻此刀的过程。\n",environment());
		command("say 原来如此，此刀并非无救。多谢这位英雄！\n");
		command("bow");
		ob->set_temp("find_chubidao",1);
		if ( ob->query_temp("find_zhantiejian") && ob->query_temp("find_qixiujian") && ob->query_temp("find_yiludao") && ob->query_temp("find_lingkongjian") && ob->query_temp("find_chubidao") )
		{
			call_out("reward", 1, ob);
		}
		destruct(obj);
		return 1;
	}


	if ((obj->query("id")=="yilu dao")&&(ob->query_temp("weaponor5")))
	{ 
		command("say 果然是宝刀刈鹿！\n");
		command("say 多谢这位英雄！\n");
		command("bow");
		ob->set_temp("find_yiludao",1);
		if ( ob->query_temp("find_zhantiejian") && ob->query_temp("find_qixiujian") && ob->query_temp("find_yiludao") && ob->query_temp("find_lingkongjian") && ob->query_temp("find_chubidao") )
		{
			call_out("reward", 1, ob);
		}
		destruct(obj);
		return 1;
	}

    return  0; 
}

int reward(object ob)
{
	object bingqipu;

	int shw = 20;
	if (!ob->query("bingqipu_success")) 	
	{
		ob->add("wlshw",shw);
		tell_object(ob,"你的武林声望增加了"+chinese_number(shw)+"点。\n");
	}
	
	bingqipu=new("/u/z/zephyr/gil_amulet");
	bingqipu->move(ob);
         
	message("system", HIM "\n【谣言】江湖传说(Bingqi Pu)：听说"+ob->name()+"得到了传说中的神秘武林至宝——纵横兵器谱。\n\n"+HIC"【闲聊】兵器贩子(Weaponor)："+ob->name()+"历尽艰辛帮助我找回五件神兵，老朽感激不尽。\n今后有什么用得着在下得地方，必当赴汤蹈火，在所不辞！！\n\n" NOR,users() );

	ob->delete_temp("weaponor5");
	ob->delete_temp("weaponor4");
	ob->delete_temp("weaponor3");
	ob->delete_temp("weaponor2");
	ob->delete_temp("weaponor1");
	ob->delete_temp("find_zhantiejian");
	ob->delete_temp("find_qixiujian");
	ob->delete_temp("find_yiludao");
	ob->delete_temp("find_lingkongjian");
	ob->delete_temp("find_chubidao");
	ob->set("bingqipu_success",1);
	command("say 这本小册子是我用天目山灵泉水加我的血写成，颇具通灵功效。\n");
	message_vision("兵器贩子从怀里掏出一本小册子，交给$N。\n",environment());
	command("say 今后英雄有难之时，我定当尽力而为，鼎力相助。\n");
	command("bye");
	destruct(this_object());
	return 1;
}
