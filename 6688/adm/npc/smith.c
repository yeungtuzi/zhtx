#include <ansi.h>
inherit NPC;
int check_legal_name(string arg);
int check_legal_id(string arg);

string *valid_type = ({
	"blade",
	"club",
	"dagger",
//        "dart",
	"fork",
	"halberd",
	"hammer", 
	"hook",
	"spear",
	"staff",
	"sword",
	"whip",				
});	

void create()
{
        set_name("张铁匠", ({ "zhang" }) );
        set("gender", "男性" );
        set("age", 52);
        set("long","张铁匠一身打铁功夫名不虚传，他打出的铁器经久耐用．\n");
        set("combat_exp", 5);
        set("attitude", "friendly");
        setup();
    
}

void init()
{	
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_ding", "ding");
        add_action("do_destroy", "destroy");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(5) ) {
                case 0:
                        say( "张铁匠粗声粗气地说道：这位" + RANK_D->query_respect(ob)
                                + "，要什么？\n");
                        break;
                case 1:
                        say( "张铁匠满脸汗水说道：这位" + RANK_D->query_respect(ob)
                                + "，我太忙了，帮不了你。\n");
                        break;
        }
}

int do_ding(string arg)
{
	string ctype, cname, ccolor, cid, desc;
	object ob, me, gold;
	string id,file,filename;                                          
	int err;
	
        me = this_player();
	id = me->query("id");
        if(!arg || sscanf(arg,"%s %s %s %s %s",ctype,ccolor,cname,cid,desc ) != 5)
        return notify_fail("指令格式：ding <type> <color> <name> <English name> <description>\n");
	if(me->is_busy())
	return notify_fail("你上一个动作还没有完成。\n");
        if((int)me->query("created_item") >= 8)
	return notify_fail("你已经拥有太多自造物品了。\n");
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
        cname="「"+cname+"」";
        desc = replace_string(desc, "$CR$", "\n");
	if( member_array(ctype,valid_type) == -1 )
			return notify_fail("这里不会做你要的东西．\n");
	
	if( mapp(me->query("custom_weapon/"+ctype)) )
			return notify_fail("你已经定做过这种兵器了。\n");	
	// by YEUNG
	// create item		
	me->set("custom_weapon/"+ctype+"/name",cname);
	me->set("custom_weapon/"+ctype+"/damage",20);
	me->set("custom_weapon/"+ctype+"/long",desc);
	me->set("custom_weapon/"+ctype+"/id",cid);
	me->save();

	{
			file = USER_WEAP_DIR + "c_" + ctype + ".c";
			err = catch(ob = new(file));
			if( err || !ob ) 
			{
				write("你觉得似乎失落了什麽重要的东西，最好通知一下巫师。\n");
				log_file("USER_WEAPON", sprintf("Fail to create %s of %s, error %s\n",
					file, this_object()->query("name"), err));
				return 0;
			}                                              
			export_uid(ob);
			ob->move(me);
			ob->init_weapon(me->query("id"),cname,cid,desc,ctype,20);
        }
	gold->add_amount(-1);
	me->add("created_item",1);
        me->start_busy(1);
	write("ＯＫ\n");
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

	me->delete("custom_weapon/"+ob->query("skill_type"));
	me->set("created_item",((int)me->query("created_item") -1));
	write ("成功销毁。\n"); 
	destruct(ob);
	return 1;

}
