// Room: /d/gumu/mishi.c 
 
inherit ROOM; 
void create() 
{ 
        set("short", "密室");
        set("long", @LONG
       这里是一间密室，四周都是石壁，只有少许光亮，
密室很大，密室顶上密密麻麻地好象写着什么。
  
LONG
        );
	set("no_fight", 1);
        set("item_desc", ([ /* sizeof() == 2 */
 
  "ding" : "这个密室的顶很光滑，上面写着许多修炼内功的心法。\n"
,
]));
       
        set("exits", ([ /* sizeof() == 3 */
   "up" : __DIR__"guancai5",
]));
        set("no_clean_up", 0);



}
void init()
{
        add_action("do_study","study");
}
int do_study(string arg)
{ object me;

me = this_player();
message_vision("$N正专心研读室顶上的文字。\n", me);
 
// if (arg != "bed" ) return 0;
if( (int)me->query_skill("force",1)<20)
    	{
            write("你内功不高，无法看清上面的字\n");
	return 1;
	}
if( (int)me->query("max_force",)<200)
    	{
            write("你内力不够，不能看清上面的字。\n");
                return 1;
	}
if( (int)me->query_skill("jiuyin-shengong",1)>100)
   	{
           write("你读了半天，发现上面说的对你太浅了。\n");
                return 1;
	}
if((int)me->query_skill("jiuyin-shengong",1)*(int)me->query_skill("jiuyin-shengong",1)*(int)me->query_skill("jiuyin-shengong",1)/10>me->query("combat_exp"))
	{
	write("你经验不够，无法继续读下去。\n");
		return 1;
	}
 
else 	{
 //me->sleep();
message_vision("$N对着那些文字研读了一会,似乎有些心得。\n", me);
  me->add("sen",-30);
	 me->improve_skill("jiuyin-shengong",(int)(me->query_skill("literate")/5+1));

 return 1;	}

}
