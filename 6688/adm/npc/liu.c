// Created by ysgl add by kiss
// Data: 1997.10.17         
// The latest changed by lysh (1997.10.31)
               
#include <ansi.h> 
inherit NPC; 
inherit F_VENDOR;

string *valid_type = ({
"cloth",
"armor",
"head",
"neck",
"surcoat",
"waist",
"wrists",
"finger",
"shield",
"hands", 
"feet",
"boots"
});	

int check_legal_name(string arg);
int check_legal_id(string arg);

void create()
{
	set_name("柳云天", ({ "liu yuntian" , "liu" , "yuntian" }));
	set("nickname", CYN"妙手裁天下"NOR); 
	set("long",
	"他是柳记布庄的少东家，也是年少有为，一双巧手号称裁尽天下之衣，他一副春风得意的样子。\n");
	set("gender", "男性");
	set("age", 25);
	set("attitude", "peaceful");
	set("vendor_goods", ([
		"/d/jingcheng/npc/obj/cloth1.c" : 1,
		"/d/jingcheng/npc/obj/cloth2.c" : 1,
                "/d/jingcheng/npc/obj/cloth3.c" : 1,
                "/d/jingcheng/npc/obj/cloth4.c" : 1,
                "/d/jingcheng/npc/obj/cloth5.c" : 1,
	]));

	set("str", 30);
	set("int", 20);
	set("con", 15);
	set("dex", 20);
	set("per", 30);
	set("force", 50);
	set("max_force", 50);
	set("force_factor", 2);
	set("combat_exp", 20000);
	set_skill("dodge", 30);
	set_skill("unarmed", 40);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 5);
	setup();
        set("chat_chance", 10);
        set("chat_msg", ({
        	"柳云天志得意满的说：“你看小店手艺还不错吧。”\n",	
        }) );
	carry_object("/obj/cloth")->wear();
}
void init()
{
	object me;
    	::init();
	seteuid(geteuid());
	add_action("do_vendor_list","list");
	add_action("do_ding", "ding");
        add_action("do_destroy", "destroy");
    	if( interactive(me = this_player()) && !is_fighting() ) 
	{
        	remove_call_out("greeting");
        	call_out("greeting", 3, me);
        	return;
        }
}

void greeting(object me)
{	
	if( !me || environment(me) != environment() ) return;
 	command("say 这位"+(string)RANK_D->query_respect(me)+"可是要选购衣物？\n");
	command("smile");
	command("say 本店经营有方，包你满意。\n");
	switch( random(5) ) {
		case 0:
			say( "柳云天笑咪咪地说道：这位" + RANK_D->query_respect(me)
				+ "，进来订身衣服吧。\n");
			break;
		case 1:
			say( "柳云天愁眉苦脸说道：这位" + RANK_D->query_respect(me)
				+ "，你又胖又矮，这帮不了你。\n");
			break;
	}

}

int do_ding(string arg)
{
	string ctype, cname, ccolor, cid, desc;
	object ob, me, gold;
	string id,file;                    
	int err;
	
        me = this_player();
	id = me->query("id");

        if(!arg || sscanf(arg,"%s %s %s %s %s",ctype,ccolor,cname,cid,desc ) != 5)
        	return notify_fail("指令格式：ding <type> <color> <name> <English name> <description>\n");
	if(me->is_busy())
		return notify_fail("你上一个动作还没有完成。\n");
	if((int)me->query("created_item") >= 8)
		return notify_fail("你已经拥有太多自造物品了。\n");
        if((int)me->query("wlshw")<10)
                return notify_fail("你的武林声望不够，他不肯为你定做衣服。\n");
	gold = present("gold_money", this_player());
        if(!gold) return notify_fail("你身上没有金子。\n");
        if((int) gold->query_amount() < 1)
        	return notify_fail("你身上没有那麽多金子。\n");
	if( !check_legal_name(cname))
		return notify_fail("");
        if( !check_legal_id(cid))
	        return notify_fail("");

	if( ccolor != "$BLK$" && 
	    ccolor != "$NOR$" &&
            ccolor != "$RED$" &&
            ccolor != "$GRN$" &&
            ccolor != "$YEL$" &&
            ccolor != "$BLU$" &&
            ccolor != "$MAG$" &&
            ccolor != "$CYN$" &&
            ccolor != "$WHT$" &&
            ccolor != "$NOR$" &&
            ccolor != "$HIR$" &&
            ccolor != "$HIG$" &&
            ccolor != "$HIY$" &&
            ccolor != "$HIB$" &&
            ccolor != "$HIM$" &&
            ccolor != "$HIC$" &&
            ccolor != "$HIW$" 
	)
	return notify_fail("不知你要什么颜色．\n");
        cname="「"+cname+"」";
	cname = ccolor + cname;
        cname = replace_string(cname, "$BLK$", BLK);
        cname = replace_string(cname, "$RED$", RED);
        cname = replace_string(cname, "$GRN$", GRN);
        cname = replace_string(cname, "$YEL$", YEL);
        cname = replace_string(cname, "$BLU$", BLU);
        cname = replace_string(cname, "$MAG$", MAG);
        cname = replace_string(cname, "$CYN$", CYN);
        cname = replace_string(cname, "$WHT$", WHT);
        cname = replace_string(cname, "$HIR$", HIR);
        cname = replace_string(cname, "$HIG$", HIG);
        cname = replace_string(cname, "$HIY$", HIY);
        cname = replace_string(cname, "$HIB$", HIB);
        cname = replace_string(cname, "$HIM$", HIM);
        cname = replace_string(cname, "$HIC$", HIC);
        cname = replace_string(cname, "$HIW$", HIW);
        cname = replace_string(cname, "$NOR$", NOR);
        cname += NOR;
        desc = replace_string(desc, "$CR$", "\n");
	if( member_array(ctype,valid_type) == -1 )
			return notify_fail("这里不会做你要的东西．\n");
        
        seteuid(getuid());



	if( mapp(me->query("custom_cloth/"+ctype)) )
			return notify_fail("你已经定做过这种衣服或者防具了。\n");	
	// by YEUNG
	// create item		
	me->set("custom_cloth/"+ctype+"/name",cname);
	me->set("custom_cloth/"+ctype+"/armor",20);
	me->set("custom_cloth/"+ctype+"/long",desc);
	me->set("custom_cloth/"+ctype+"/id",cid);
	me->save();

	{
			file = USER_CLOTH_DIR + "cloth.c";
			err = catch(ob = new(file));
			if( err || !ob ) 
			{
				write("你觉得似乎失落了什麽重要的东西，最好通知一下巫师。\n");
				log_file("USER_CLOTH", sprintf("Fail to create %s of %s, error %s\n",
					file, this_object()->query("name"), err));
				return 0;
			}                                              
			export_uid(ob);
			ob->move(me);      
			ob->init_cloth(me->query("id"),cname,cid,desc,ctype,20);
        }
        me->set("wlshw",(int)me->query("wlshw")-10);
	me->add("created_item",1);
        me->start_busy(1);
	write(RED"柳云天笑嘻嘻的说：“做好了。”\n"NOR);
	me->save();
	return 1;
}

int check_legal_name(string name)
{
        int cp, i;

        for (i = 0; ; i++) {
                cp = name[i];
                if (cp == 0) break;

                if (cp <= ' ') {
                        write("对不起，中文名字不能用控制字元。\n");
                        return 0;
                }

                if (cp < 13312 || cp > 40959) {
                        write("对不起，名字必需是中文。\n");
                        return 0;
                }

                if (i >= 20) {
                        write("对不起，中文名字必须是一到二十个中文字。\n");
                        return 0;
                }
        }

        if (i < 1) {
                write("对不起，中文名字必须是一到二十个中文字。\n");
                return 0;
        }

        return 1;
}

int check_legal_id(string name)
{
        int i;
        i = strlen(name);
        if( (strlen(name) < 3) || (strlen(name) > 20 ) ) {
                write("对不起，英文名字必须是三到二十个字字。\n");
                return 0;
        }

	while(i--)
		if( name[i]<'a' || name[i]>'z' ) {
			write("对不起，你的英文名字只能用英文字母。\n");
			return 0;
		}

	return 1;
}

int do_destroy(string arg)
{
	object me,ob;
	string file;

	me=this_player();

	if( !arg) 
        	return notify_fail("你销毁什么东西。\n");   
	if( !objectp(ob = present(arg, me)) )
        	return notify_fail("你身上没有这样东西。\n");

	if( (ob->query("owner"))!=(me->query("id")) )
		return notify_fail("你只可销毁自己订的物品。\n");

	if(me->is_busy())
        	return notify_fail("你上一个动作还没有完成。\n");

	if( ob->query("equipped") )
        	return notify_fail("你不可销毁正装备的物品。\n");

	me->start_busy(1);

	me->delete("custom_cloth/"+ob->query("armor_type"));
	destruct(ob);
	me->set("created_item",((int)me->query("created_item") -1));
	write ("成功销毁。\n");
	return 1;

}
