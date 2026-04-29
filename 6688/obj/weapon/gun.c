// /obj/weapon/gun.c 
// an example weapon

#include <weapon.h>

inherit GUN;

int do_load(object ob);

void create()
{
	set_name("步枪", ({ "gun", "rifle" }) );
	set_weight(3750);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "支");
		set("long", "这是一支只能单发射击的来复枪,已经有点儿过时了.\n");
		set("value", 14000);
		set("material", "steel");
                set("rounds_amount", 1);
                set("rounds_name", "7.62mm步枪子弹");
                set("max_rounds", 5);
	}
	init_gun(15);

// These properties are optional, if you don't set them, it will use the
// default values.
                set("wield_msg", "$N把$n握在手中,打开保险,准备射击.\n");
                set("unequip_msg", "$N合上$n的保险,背在背上.\n");

// The setup() is required.

	setup();
}

void init()
{
       add_action("do_reload","reload");
       add_action("do_unload","unload");
}

int do_reload(string arg)
{
       object * ob;
       int i, counter;
       object me;

       me = this_player();
       counter=0;
       if ( (!arg) || (arg=="bullet") ) {
               ob = all_inventory(me);
                for(i=0; i<sizeof(ob); i++) {
               if( (string)ob[i]->query("name") == "bullet"  && 
       (string)ob[i]->query("type") == query("rounds_name"))
         { do_load(ob[i]);
          counter++;}
                }
       if (counter== 0 ) return notify_fail("你没有可用的子弹了!\n");
              return 1;
         }
              return notify_fail("你到底要装入什么?\n");
        }

int do_load(object ob)
{
     int max_rounds,have_rounds,temp;

     max_rounds=query("max_rounds");
     have_rounds=query("rounds_amount");
     temp=max_rounds-have_rounds;
     if (temp<=0) return notify_fail("你的弹匣是满的,不需要补充弹药.\n");
     have_rounds=ob->query("amount");
     if (have_rounds>=temp){
         have_rounds -= temp;
         set("rounds_amount",max_rounds);
         ob->set("amount", have_rounds);
         write("你把"+query("name")+"的弹匣重新装满了.\n");
         return 1;
     } else {
         ob->set("amount", 0);
         temp=query("rounds_amount");
         temp+=have_rounds;
         set("rounds_amount",temp);
         write("你把剩下的"+ob->query("short")+"全部填进弹匣.\n");
         return 1;
     }
}

int do_unload(string arg)
{
         int have_rounds,temp,i,counter;
         object * ob;
         object me,newob;
         counter =0;
         me = this_player();
         ob = all_inventory(me);
         have_rounds=query("rounds_amount");
         for(i=0; i<sizeof(ob); i++) {
       if( (string)ob[i]->query("name") == "bullet"  
       && (string)ob[i]->query("type")!= query("rounds_name") ) 
        {
            counter += 1;
            ob[i]->add("amount",have_rounds);
            set("rounds_amount", 0);
            write("你卸下弹匣中的子弹.\n");
            return 1;}
         }
         if ( counter == 0 ) {
            newob = new(OBJ_DIR"weapon/bullet");
            newob -> move (me);
            newob -> set_amount(have_rounds);
            write("你卸下弹匣中的子弹.\n");
            return 1;
         }
}
