/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** error_handling
*/

#include "rpg.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static const char *src[207] = {"assets/game/player.png",
"assets/game/zombie3.png", "assets/game/unknown.png", "assets/game/1.jpg",
"assets/game/health.jpg", "assets/game/stamina.jpg", "assets/game/Bar.png",
"assets/game/barn.png", "assets/game/bathub.png", "assets/game/betterave.png",
"assets/game/bighouse.png", "assets/game/bus.png", "assets/game/camp.png",
"assets/game/darkoakgreenhouse.png", "assets/game/delievery_car.png",
"assets/game/dirt.jpg", "assets/game/fisherman.png",
"assets/game/fisherman2.png", "assets/game/forge.png", "assets/game/grass.jpg",
"assets/game/gypsi.png", "assets/game/hospital.png", "assets/game/house1.png",
"assets/game/house2.png", "assets/game/house3.png", "assets/game/house4.png",
"assets/game/house5.png", "assets/game/house_hero.png",
"assets/game/oldpickup.png", "assets/game/pave.jpg",
"assets/game/pighouse.png", "assets/game/road.jpg",
"assets/game/ruined_house.png", "assets/game/ruined_mall.png",
"assets/game/sand.jpg", "assets/game/serre.png", "assets/game/townhall.png",
"assets/game/townhallruined.png", "assets/game/tree.png",
"assets/game/wallfoot.jpg",
"assets/game/water.jpg", "assets/game/wheat_crop.png", "assets/game/bloc.png",
"assets/game/hand.png", "assets/game/reload.png",
"assets/game/switch_replace.png", "assets/game/Pause.png",
"assets/game/date.png", "assets/game/ground.jpg",
"assets/game/map.jpg", "assets/game/player_info.jpg", "assets/game/quest.jpg",
"assets/game/screen_on.jpg", "assets/game/skill_tree.jpg",
"assets/game/tablet_menu.png", "assets/game/aymeric.png",
"assets/game/bag.png", "assets/game/booksell.png", "assets/game/bootsis.png",
"assets/game/chest.png", "assets/game/chest_menu.png",
"assets/game/chocolatine.png", "assets/game/hugo.png",
"assets/game/sisterhat.png", "assets/game/square_item.png",
"assets/game/bg_tablet.jpg", "assets/game/AK.ogg", "assets/game/Eat.ogg",
"assets/game/Fight.ogg", "assets/game/IDEA_RPG_Fight.ogg",
"assets/game/RPG_Fight.ogg", "assets/game/ground_mineshaft.jpg",
"assets/game/horror.ogg", "assets/game/intro_rpg.ogg",
"assets/game/minenetrance.png", "assets/game/quest",
"assets/game/quest/aymeric.png", "assets/game/quest/bg_tablet.jpg",
"assets/game/quest/hugo.png", "assets/game/quest/missions.jpg",
"assets/game/quest/missions_done.jpg", "assets/game/tablet",
"assets/game/tablet/bg_skill_tree.jpg", "assets/game/tablet/force_1.png",
"assets/game/tablet/force_2.png", "assets/game/tablet/life_1.png",
"assets/game/tablet/life_2.png", "assets/game/tablet/stamina_1.png",
"assets/game/tablet/stamina_2.png", "assets/game/zombie.ogg",
"assets/boss", "assets/boss/How_to_play_boss.png",
"assets/boss/boss.png",
"assets/boss/heart_player.png", "assets/boss/msg_boss_one.png",
"assets/boss/msg_boss_two.png", "assets/boss/msg_boss_zero.png",
"assets/boss/os.png", "assets/boss/ouch.png", "assets/boss/paf.png",
"assets/boss/ring.jpg", "assets/boss/skelleton.png",
"assets/boss/versus.png",
"assets/font/Roboto-Black.ttf", "assets/font/verdana.ttf",
"assets/font/pixel.ttf", "assets/intro/background.png",
"assets/intro/button_skip.png",
"assets/intro/arrow_right.png", "assets/intro/bar_info.png",
"assets/intro/boss_zombie.jpg",
"assets/intro/button_next.png", "assets/intro/cinema.jpeg",
"assets/intro/clap_board.png", "assets/intro/intro_rpg.ogg",
"assets/intro/invasion_zombie.jpg", "assets/intro/last_mission.jpg",
"assets/intro/last_mission_play.jpg", "assets/intro/play_game.png",
"assets/intro/post_world.jpg", "assets/intro/save_sister.png",
"assets/intro/search_job.jpg", "assets/intro/bubulle_legende_five.png",
"assets/intro/bubulle_legende_four.png",
"assets/intro/bubulle_legende_one.png",
"assets/intro/bubulle_legende_six.png",
"assets/intro/bubulle_legende_three.png",
"assets/intro/bubulle_legende_two.png", "assets/load_game/Delete_save.png",
"assets/load_game/Load_game_save.png", "assets/load_game/Load_save.png",
"assets/load_game/New_game_save.png", "assets/load_game/Zelter.png",
"assets/menu/audio_options.jpg", "assets/menu/button_volume.png",
"assets/menu/colored_button.jpg", "assets/menu/empty_fps.jpg",
"assets/menu/empty_size.jpg", "assets/menu/fps_options.jpg",
"assets/menu/panneau_menu.png", "assets/menu/reseau.jpg",
"assets/menu/scrolling_bar.jpg", "assets/menu/switch_button.png",
"assets/menu/triangle.png", "assets/menu/video_options.jpg",
"assets/menu/volume_bar.jpg", "assets/menu/keyboard.png",
"assets/menu/options.jpg", "assets/menu/screen_size.jpg",
"assets/menu/tablette.png", "assets/menu/bg_controls.jpg",
"assets/new_game/Cop_basic.png", "assets/new_game/Cop_blue.png",
"assets/new_game/Cop_green.png", "assets/new_game/Cop_pink.png",
"assets/new_game/Cop_red.png", "assets/new_game/Researcher_basic.png",
"assets/new_game/Researcher_blue.png",
"assets/new_game/Researcher_green.png",
"assets/new_game/Researcher_pink.png",
"assets/new_game/Researcher_red.png",
"assets/new_game/Soldier_basic.png",
"assets/new_game/Soldier_blue.png",
"assets/new_game/Soldier_green.png",
"assets/new_game/Soldier_pink.png",
"assets/new_game/Soldier_red.png",
"assets/new_game/Sporty_basic.png",
"assets/new_game/Sporty_blue.png",
"assets/new_game/Sporty_green.png",
"assets/new_game/Sporty_pink.png",
"assets/new_game/Sporty_red.png", "assets/new_game/cat.png",
"assets/new_game/Cop.png", "assets/new_game/Researcher.png",
"assets/new_game/Soldier.png", "assets/new_game/Sporty.png",
"assets/new_game/LylianRPG.png", "assets/new_game/MatthiasRPG.png",
"assets/new_game/QuentinRPG.png", "assets/game/zombie1.png",
"assets/game/zombie2.png", "assets/game/bushe.png", "assets/game/hearth.png",
"assets/game/eclair.png", "assets/game/zombie5.png", "assets/game/star.png",
"assets/game/zombie7.png", "assets/game/tablet/player_info.jpg",
"assets/game/zombie6.png", "assets/game/zombie4.png",
"assets/assets/letter.png", "assets/assets/batleft.png",
"assets/assets/key.png", "assets/assets/potato.png",
"assets/assets/seringue.png", "assets/assets/ammo.png",
"assets/assets/bread.png", "assets/assets/ak47lrft.png",
"assets/assets/carrot.png", "assets/assets/money.png",
"assets/assets/medkit.png", "data/map.uwu", "data/map_p.uwu",
"data/save_1.txt", "data/save_2.txt", "data/save_3.txt",
"assets/game/albedo_ground.jpg"};

int error_handling(void)
{
    int fd = 0;

    for (int i = 0; i < 207; i++) {
        fd = open(src[i], O_RDONLY);
        if (fd == -1) {
            write(2, src[i], my_strlen(src[i]));
            return (84);
        }
        close(fd);
    }
    return (0);
}
